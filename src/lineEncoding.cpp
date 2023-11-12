#include <iostream>
#include <SFML/Graphics.hpp>
#include "openWindow.h"
using namespace std;

void lineEncoding(const std::string &dataStream, int &choice)
{
    // Define window dimensions, padding
    const int windowWidth = 2400; // Increased to accommodate both streams
    const int windowHeight = 1000;
    const int padding = 20;
    bool chk = true;

    // Create SFML window
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Original and NRZ-L Encoding");

    sf::Font font;
    if (!font.loadFromFile("assets/font3.otf"))
    {
        cerr << "Error loading font file" << endl;
        return; // Exit the function if the font fails to load
    }
    sf::Text text0("Line Encoder", font, 80);
    text0.setFillColor(sf::Color::Black);

    sf::Text text("ORIGINAL", font, 30);
    text.setFillColor(sf::Color::Black);

    sf::Text text2("NRZ-L", font, 30);
    text2.setFillColor(sf::Color::Black);

    sf::Text text3("NRZ-I", font, 30);
    text3.setFillColor(sf::Color::Black);

    sf::Text text4("MANCHESTER", font, 30);
    text4.setFillColor(sf::Color::Black);

    sf::Text text5("DIFFERENTIAL MANCHESTER", font, 30);
    text5.setFillColor(sf::Color::Black);

    sf::Text text6("BIPOLAR AMI", font, 30);
    text6.setFillColor(sf::Color::Black);

    sf::Text text7("B8ZS SCRAMBLED AMI", font, 30);
    text7.setFillColor(sf::Color::Black);

    sf::Text text8("HDB3 SCRAMBLED AMI", font, 30);
    text8.setFillColor(sf::Color::Black);

    string longPal = findLongestPalindrome(dataStream);
    sf::Text text9("Longest palindrome in the data stream is: " + longPal, font, 30);
    text9.setFillColor(sf::Color::Blue);

    sf::Text text10("Data Stream given was:" + dataStream, font, 30);
    text10.setFillColor(sf::Color::Blue);

    // Calculate the width of each rectangle based on the window and data stream size
    const float rectangleWidth = (static_cast<float>(windowWidth) - 4 * padding) / (2 * dataStream.size());

    // Create vectors for original data stream
    std::vector<sf::RectangleShape> originalRectangles;
    std::vector<sf::Text> originalTexts;

    for (size_t i = 0; i < dataStream.size(); ++i)
    {
        // Create rectangle for original data stream
        sf::RectangleShape rect(sf::Vector2f(rectangleWidth, 40));
        if (dataStream[i] == '1')
        {
            rect.setPosition(padding + i * rectangleWidth + 2, windowHeight / 3 - 20);
            rect.setFillColor(sf::Color::Blue);
            rect.setOutlineThickness(2);
            rect.setOutlineColor(sf::Color::Black);
            originalRectangles.push_back(rect);
        }
        else
        {
            rect.setPosition(padding + i * rectangleWidth + 2, windowHeight / 3 - 20);
            // rect.setFillColor(sf::Color::Blue);
            // rect.setOutlineThickness(2);
            // rect.setOutlineColor(sf::Color::Black);
            originalRectangles.push_back(rect);
        }

        // Create text for original data stream
        sf::Text bitText(dataStream[i], font, 20);
        bitText.setFillColor(sf::Color::Black);

        if (dataStream[i] == '0')
        {
            bitText.setPosition((padding + i * rectangleWidth) + rectangleWidth / 2, windowHeight / 3 - 50);
        }
        else if (dataStream[i] == '1')
        {
            bitText.setPosition((padding + i * rectangleWidth) + rectangleWidth / 2, windowHeight / 3 - 50);
        }

        originalTexts.push_back(bitText);
    }

    // Create vectors for NRZ-L encoding
    std::vector<sf::RectangleShape> nrzlRectangles;
    std::vector<sf::Text> nrzlTexts;

    for (size_t i = 0; i < dataStream.size(); ++i)
    {
        // Create rectangle for NRZ-L encoding
        sf::RectangleShape rect(sf::Vector2f(rectangleWidth, -40));

        if (dataStream[i] == '0')
        {
            rect.setPosition(padding + i * rectangleWidth + 2, windowHeight / 2 + 30);
            rect.setFillColor(sf::Color::Green);
            rect.setOutlineThickness(2);
            rect.setOutlineColor(sf::Color::Black);
        }
        else if (dataStream[i] == '1')
        {
            rect.setPosition(padding + i * rectangleWidth + 2, windowHeight / 2 + 30);
            rect.setSize(sf::Vector2f(rectangleWidth, 40));
            rect.setFillColor(sf::Color::Red);
            rect.setOutlineThickness(2);
            rect.setOutlineColor(sf::Color::Black);
        }

        nrzlRectangles.push_back(rect);

        // Create text for NRZ-L encoding
        sf::Text bitText(dataStream[i], font, 20);
        bitText.setFillColor(sf::Color::Black);

        if (dataStream[i] == '0')
        {
            bitText.setPosition((padding + i * rectangleWidth) + rectangleWidth / 2, windowHeight / 2.5 + 50);
        }
        else if (dataStream[i] == '1')
        {
            bitText.setPosition((padding + i * rectangleWidth) + rectangleWidth / 2, windowHeight / 2.5 + 50);
        }

        nrzlTexts.push_back(bitText);
    }

    // NRZ- I
    std::vector<sf::RectangleShape> nrziRectangles;
    std::vector<sf::Text> nrziTexts;

    // Initial state for NRZ-I encoding
    int prev = 40;
    sf::RectangleShape rect(sf::Vector2f(rectangleWidth, prev));

    for (size_t i = 0; i < dataStream.size(); ++i)
    {
        // Create rectangle for NRZ-I encoding
        // Use a positive height for NRZ-I

        if (dataStream[i] == '0')
        {
            rect.setSize(sf::Vector2f(rectangleWidth, prev));
            rect.setPosition(padding + i * rectangleWidth + 2, windowHeight / 2 + 30);
            rect.setFillColor(sf::Color::Green);
            rect.setOutlineThickness(2);
            rect.setOutlineColor(sf::Color::Black);
        }
        else
        {
            rect.setPosition(padding + i * rectangleWidth + 2, windowHeight / 2 + 30);
            if (i == 0)
                rect.setSize(sf::Vector2f(rectangleWidth, prev));
            rect.setSize(sf::Vector2f(rectangleWidth, -1 * prev));
            prev = -1 * prev;
            rect.setFillColor(sf::Color::Red);
            rect.setOutlineThickness(2);
            rect.setOutlineColor(sf::Color::Black);
        }

        nrziRectangles.push_back(rect);

        // Create text for NRZ-I encoding
        sf::Text bitText(dataStream[i], font, 20);
        bitText.setFillColor(sf::Color::Black);

        bitText.setPosition((padding + i * rectangleWidth) + rectangleWidth / 2, windowHeight / 2.5 + 50);

        nrziTexts.push_back(bitText);
    }

    // manchester encoding

    string manDatastream = "";
    for (int i = 0; i < dataStream.size(); i++)
    {
        if (dataStream[i] == '0')
        {
            manDatastream += "10";
        }
        else
        {
            manDatastream += "01";
        }
    }

    cout << manDatastream << endl;

    std::vector<sf::RectangleShape> manRectangles;
    std::vector<sf::Text> manTexts;

    sf::RectangleShape manrect(sf::Vector2f(rectangleWidth / 2, 40));

    for (size_t i = 0; i < manDatastream.size(); ++i)
    {

        if (manDatastream[i] == '0')
        {
            manrect.setSize(sf::Vector2f(rectangleWidth / 2, 40));
            manrect.setPosition(padding + (i * rectangleWidth + 2) / 2 + 2, windowHeight / 2 + 30);
            manrect.setFillColor(sf::Color::Green);
            manrect.setOutlineThickness(2);
            manrect.setOutlineColor(sf::Color::Black);
        }
        else
        {
            manrect.setPosition(padding + (i * rectangleWidth + 2) / 2 + 2, windowHeight / 2 + 30);
            manrect.setSize(sf::Vector2f(rectangleWidth / 2, -40));
            manrect.setFillColor(sf::Color::Red);
            manrect.setOutlineThickness(2);
            manrect.setOutlineColor(sf::Color::Black);
        }

        manRectangles.push_back(manrect);

        // Create text for NRZ-I encoding
        sf::Text bitText(dataStream[i], font, 20);
        bitText.setFillColor(sf::Color::Black);

        bitText.setPosition((padding + i * rectangleWidth) + rectangleWidth / 2, windowHeight / 2.5 + 50);

        manTexts.push_back(bitText);
    }

    // differential manchester
    std::string diffManStream;
    char lastState = '0'; // Initialize the last state to '0'
    bool first = true;
    for (char bit : dataStream)
    {
        if (bit == '0')
        {
            if (first == true)
            {
                diffManStream += (lastState == '0') ? "01" : "10";
                first = false;
            }
            else
            {
                diffManStream += (lastState == '0') ? "10" : "01";
            } // Transition from last state to '0'
        }
        else if (bit == '1')
        {

            if (first == true)
            {
                diffManStream += (lastState == '0') ? "10" : "01";
                first = false;
            }
            else
            {
                diffManStream += (lastState == '1') ? "10" : "01";
            } // Transition from last state to '1'
        }
        else
        {
            std::cerr << "Invalid input: " << bit << std::endl;
        }

        lastState = diffManStream.back();
    }

    std::vector<sf::RectangleShape> diffmanRectangles;
    std::vector<sf::Text> diffmanTexts;

    sf::RectangleShape diffmanrect(sf::Vector2f(rectangleWidth / 2, 40));

    for (size_t i = 0; i < diffManStream.size(); ++i)
    {

        if (diffManStream[i] == '0')
        {
            diffmanrect.setSize(sf::Vector2f(rectangleWidth / 2, 40));
            diffmanrect.setPosition(padding + (i * rectangleWidth + 2) / 2 + 2, windowHeight / 2 + 30);
            diffmanrect.setFillColor(sf::Color::Green);
            diffmanrect.setOutlineThickness(2);
            diffmanrect.setOutlineColor(sf::Color::Black);
        }
        else
        {
            diffmanrect.setPosition(padding + (i * rectangleWidth + 2) / 2 + 2, windowHeight / 2 + 30);
            diffmanrect.setSize(sf::Vector2f(rectangleWidth / 2, -40));
            diffmanrect.setFillColor(sf::Color::Red);
            diffmanrect.setOutlineThickness(2);
            diffmanrect.setOutlineColor(sf::Color::Black);
        }

        diffmanRectangles.push_back(diffmanrect);

        // Create text for NRZ-I encoding
        sf::Text bitText(dataStream[i], font, 20);
        bitText.setFillColor(sf::Color::Black);

        bitText.setPosition((padding + i * rectangleWidth) + rectangleWidth / 2, windowHeight / 2.5 + 50);

        diffmanTexts.push_back(bitText);
    }

    // BIPOLAR AMI

    string amiStream;
    bool toggle = false;
    for (char bit : dataStream)
    {
        if (bit == '0')
        {
            amiStream += "0";
        }
        else
        {
            if (toggle == false)
            {
                amiStream += "1";
            }
            else
            {
                amiStream += "2";
            }
            toggle = !toggle;
        }
    }
    std::vector<sf::RectangleShape> amiRectangles;
    std::vector<sf::Text> amiTexts;

    sf::RectangleShape amirect(sf::Vector2f(rectangleWidth, 40));

    for (size_t i = 0; i < amiStream.size(); ++i)
    {

        if (amiStream[i] == '0')
        {
            amirect.setSize(sf::Vector2f(rectangleWidth, 0));
            amirect.setPosition(padding + i * rectangleWidth + 2, windowHeight / 2 + 30);
            amirect.setFillColor(sf::Color::Green);
            amirect.setOutlineThickness(2);
            amirect.setOutlineColor(sf::Color::Black);
        }
        else if (amiStream[i] == '1')
        {
            amirect.setSize(sf::Vector2f(rectangleWidth, -40));
            amirect.setPosition(padding + i * rectangleWidth + 2, windowHeight / 2 + 30);
            amirect.setFillColor(sf::Color::Green);
            amirect.setOutlineThickness(2);
            amirect.setOutlineColor(sf::Color::Black);
        }
        else
        {
            amirect.setSize(sf::Vector2f(rectangleWidth, 40));
            amirect.setPosition(padding + i * rectangleWidth + 2, windowHeight / 2 + 30);
            amirect.setFillColor(sf::Color::Green);
            amirect.setOutlineThickness(2);
            amirect.setOutlineColor(sf::Color::Black);
        }

        amiRectangles.push_back(amirect);

        // Create text for NRZ-I encoding
        sf::Text bitText(dataStream[i], font, 20);
        bitText.setFillColor(sf::Color::Black);

        bitText.setPosition((padding + i * rectangleWidth) + rectangleWidth / 2, windowHeight / 2.5 + 50);

        amiTexts.push_back(bitText);
    }

    // b8zs scrambling
    string b8zsStream;
    int consecutiveZeros = 0;
    for (char bit : dataStream)
    {
        if (bit == '0')
        {
            consecutiveZeros++;
        }
        else
        {
            consecutiveZeros = 0;
        }

        if (consecutiveZeros == 8)
        {
            // Replace eight consecutive zeros with the B8ZS pattern
            b8zsStream = b8zsStream.erase(b8zsStream.size() - 7);
            b8zsStream += "000VB0VB";
            consecutiveZeros = 0;
        }
        else
        {
            b8zsStream += bit;
        }
    }

    std::vector<sf::RectangleShape> b8zsRectangles;
    std::vector<sf::Text> b8zsTexts;
    int amilastState = -1;
    sf::RectangleShape b8zsrect(sf::Vector2f(rectangleWidth, 40));

    for (size_t i = 0; i < b8zsStream.size(); ++i)
    {
        if (b8zsStream[i] == '0')
        {
            b8zsrect.setSize(sf::Vector2f(rectangleWidth, 0));
            b8zsrect.setPosition(padding + i * rectangleWidth + 2, windowHeight / 1.35 + 30);
            b8zsrect.setFillColor(sf::Color::Green);
            b8zsrect.setOutlineThickness(2);
            b8zsrect.setOutlineColor(sf::Color::Black);
        }
        else if (b8zsStream[i] == '1')
        {
            if (amilastState == -1)
            {
                b8zsrect.setSize(sf::Vector2f(rectangleWidth, -40));
                amilastState = 1;
            }
            else
            {
                b8zsrect.setSize(sf::Vector2f(rectangleWidth, 40));
                amilastState = -1;
            }
            b8zsrect.setPosition(padding + i * rectangleWidth + 2, windowHeight / 1.35 + 30);
            b8zsrect.setFillColor(sf::Color::Green);
            b8zsrect.setOutlineThickness(2);
            b8zsrect.setOutlineColor(sf::Color::Black);
        }
        else if (b8zsStream[i] == 'B')
        {
            if (amilastState == -1)
            {
                b8zsrect.setSize(sf::Vector2f(rectangleWidth, 40));
                amilastState = -1;
            }
            else
            {
                b8zsrect.setSize(sf::Vector2f(rectangleWidth, -40));
                amilastState = 1;
            }
            b8zsrect.setPosition(padding + i * rectangleWidth + 2, windowHeight / 1.35 + 30);
            b8zsrect.setFillColor(sf::Color::Green);
            b8zsrect.setOutlineThickness(2);
            b8zsrect.setOutlineColor(sf::Color::Black);
        }
        else if (b8zsStream[i] == 'V')
        {
            if (amilastState == -1)
            {
                b8zsrect.setSize(sf::Vector2f(rectangleWidth, 40));
                amilastState = 1;
            }
            else
            {
                b8zsrect.setSize(sf::Vector2f(rectangleWidth, -40));
                amilastState = -1;
            }
            b8zsrect.setPosition(padding + i * rectangleWidth + 2, windowHeight / 1.35 + 30);
            b8zsrect.setFillColor(sf::Color::Green);
            b8zsrect.setOutlineThickness(2);
            b8zsrect.setOutlineColor(sf::Color::Black);
        }

        b8zsRectangles.push_back(b8zsrect);

        sf::Text bitText(b8zsStream[i], font, 20);
        bitText.setFillColor(sf::Color::Black);

        bitText.setPosition((padding + i * rectangleWidth) + rectangleWidth / 2, windowHeight / 1.35 - 50);

        b8zsTexts.push_back(bitText);
    }

    // hdb3 scrambling
    std::string hdb3Stream;
    int consecutiveZeros2 = 0;
    bool alternate = false; // if even?

    for (char bit : dataStream)
    {
        if (bit == '0')
        {
            consecutiveZeros2++;
            hdb3Stream += bit;
            if (consecutiveZeros2 == 4)
            {
                // Update nonzero pulses count
                hdb3Stream.erase(hdb3Stream.size() - 4);

                // Append the appropriate pattern
                if (alternate == false)
                {
                    hdb3Stream += "B00V";
                }
                else
                {
                    hdb3Stream += "000V";
                }
                alternate = !alternate;
                consecutiveZeros2 = 0;
            }
        }
        else
        {
            consecutiveZeros2 = 0;
            hdb3Stream += bit;
        }
    }

    std::vector<sf::RectangleShape> hdb3Rectangles;
    std::vector<sf::Text> hdb3Texts;
    int amilastState2 = -1;
    sf::RectangleShape hdb3rect(sf::Vector2f(rectangleWidth, 40));

    for (size_t i = 0; i < hdb3Stream.size(); ++i)
    {
        if (hdb3Stream[i] == '0')
        {
            hdb3rect.setSize(sf::Vector2f(rectangleWidth, 0));
            hdb3rect.setPosition(padding + i * rectangleWidth + 2, windowHeight / 1.35 + 30);
            hdb3rect.setFillColor(sf::Color::Green);
            hdb3rect.setOutlineThickness(2);
            hdb3rect.setOutlineColor(sf::Color::Black);
        }
        else if (hdb3Stream[i] == '1')
        {
            if (amilastState2 == -1)
            {
                hdb3rect.setSize(sf::Vector2f(rectangleWidth, -40));
                amilastState2 = 1;
            }
            else
            {
                hdb3rect.setSize(sf::Vector2f(rectangleWidth, 40));
                amilastState2 = -1;
            }
            hdb3rect.setPosition(padding + i * rectangleWidth + 2, windowHeight / 1.35 + 30);
            hdb3rect.setFillColor(sf::Color::Green);
            hdb3rect.setOutlineThickness(2);
            hdb3rect.setOutlineColor(sf::Color::Black);
        }
        else if (hdb3Stream[i] == 'V')
        {
            if (amilastState2 == -1)
            {
                hdb3rect.setSize(sf::Vector2f(rectangleWidth, 40));
                amilastState2 = -1;
            }
            else
            {
                hdb3rect.setSize(sf::Vector2f(rectangleWidth, -40));
                amilastState2 = 1;
            }
            hdb3rect.setPosition(padding + i * rectangleWidth + 2, windowHeight / 1.35 + 30);
            hdb3rect.setFillColor(sf::Color::Green);
            hdb3rect.setOutlineThickness(2);
            hdb3rect.setOutlineColor(sf::Color::Black);
        }
        else if (hdb3Stream[i] == 'B')
        {
            if (amilastState2 == -1)
            {
                hdb3rect.setSize(sf::Vector2f(rectangleWidth, -40));
                amilastState2 = 1;
            }
            else
            {
                hdb3rect.setSize(sf::Vector2f(rectangleWidth, 40));
                amilastState2 = -1;
            }
            hdb3rect.setPosition(padding + i * rectangleWidth + 2, windowHeight / 1.35 + 30);
            hdb3rect.setFillColor(sf::Color::Green);
            hdb3rect.setOutlineThickness(2);
            hdb3rect.setOutlineColor(sf::Color::Black);
        }

        hdb3Rectangles.push_back(hdb3rect);

        sf::Text bitText(hdb3Stream[i], font, 20);
        bitText.setFillColor(sf::Color::Black);

        bitText.setPosition((padding + i * rectangleWidth) + rectangleWidth / 2, windowHeight / 1.35 - 50);

        hdb3Texts.push_back(bitText);
    }

    sf::RectangleShape horizontalBaseline(sf::Vector2f(dataStream.size() * rectangleWidth, 1));
    horizontalBaseline.setPosition(padding, windowHeight / 3 + 20); // Bottom of the rectangles
    horizontalBaseline.setFillColor(sf::Color::Black);

    // Create vertical baseline as a solid black line
    sf::RectangleShape verticalBaseline(sf::Vector2f(3, windowHeight));
    verticalBaseline.setPosition(padding, 0);
    verticalBaseline.setFillColor(sf::Color::Black);

    // Create vertical dotted lines after every digit
    std::vector<sf::RectangleShape> dottedLines;
    int i = dataStream.size();

    while (i > 0)
    {
        sf::RectangleShape dottedLine(sf::Vector2f(0.5, windowHeight));
        dottedLine.setPosition(padding + (i * rectangleWidth) + 2, windowHeight / 3 - 30);
        dottedLine.setFillColor(sf::Color::Black);
        dottedLine.setOutlineThickness(0);
        dottedLine.setOutlineColor(sf::Color::Black);
        dottedLines.push_back(dottedLine);
        i--;
    }

    // Main loop
    while (window.isOpen())
    {
        window.clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Clear the window
        window.clear(sf::Color::White);

        // Draw the vertical baseline
        window.draw(verticalBaseline);

        window.draw(horizontalBaseline);

        text0.setPosition(windowWidth / 4 + 20, 20);
        window.draw(text0);

        text9.setPosition(windowWidth / 3, windowHeight / 5);
        window.draw(text9);

        text10.setPosition(windowWidth / 20, windowHeight / 5);
        window.draw(text10);

        // Draw rectangles for original data stream
        text.setPosition(windowWidth / 2, windowHeight / 3 - 20);
        window.draw(text);
        for (const auto &rect : originalRectangles)
        {
            window.draw(rect);
        }

        // Draw text for original data stream
        for (const auto &bitText : originalTexts)
        {
            window.draw(bitText);
        }

        //// Draw rectangles for NRZ-L encoding

        if (choice == 1)
        {
            text2.setPosition(windowWidth / 2, windowHeight / 2);
            window.draw(text2);
            for (const auto &rect : nrzlRectangles)
            {
                window.draw(rect);
            }

            // Draw text for NRZ-L encoding
            for (const auto &bitText : nrzlTexts)
            {
                window.draw(bitText);
            }
        }

        // NRZI encoding
        if (choice == 2)
        {
            text3.setPosition(windowWidth / 2, windowHeight / 2);
            window.draw(text3);

            for (const auto &rect : nrziRectangles)
            {
                window.draw(rect);
            }

            // Draw text for NRZ-I encoding
            for (const auto &bitText : nrziTexts)
            {
                window.draw(bitText);
            }
        }

        // manchester
        if (choice == 3)
        {
            text4.setPosition(windowWidth / 2, windowHeight / 2);
            window.draw(text4);

            for (const auto &manrect : manRectangles)
            {
                window.draw(manrect);
            }
            for (const auto &bitText : manTexts)
            {
                window.draw(bitText);
            }
        }

        // differential manchester
        if (choice == 4)
        {
            text5.setPosition(windowWidth / 2, windowHeight / 2);
            window.draw(text5);
            for (const auto &diffmanrect : diffmanRectangles)
            {
                window.draw(diffmanrect);
            }
            for (const auto &bitText : diffmanTexts)
            {
                window.draw(bitText);
            }
        }

        // ami
        if (choice / 10 == 5 || choice == 5)
        {
            text6.setPosition(windowWidth / 2, windowHeight / 2);
            window.draw(text6);
            for (const auto &amirect : amiRectangles)
            {
                window.draw(amirect);
            }
            for (const auto &bitText : amiTexts)
            {
                window.draw(bitText);
            }
        }

        // b8zs scramble
        if (choice == 51)
        {
            text7.setPosition(windowWidth / 2, windowHeight / 1.35);
            window.draw(text7);
            for (const auto &b8zsrect : b8zsRectangles)
            {
                window.draw(b8zsrect);
            }
            for (const auto &bitText : b8zsTexts)
            {
                window.draw(bitText);
            }
        }

        // hdb3 scramble
        if (choice == 52)
        {
            text8.setPosition(windowWidth / 2, windowHeight / 1.35);
            window.draw(text8);
            for (const auto &hdb3rect : hdb3Rectangles)
            {
                window.draw(hdb3rect);
            }
            for (const auto &bitText : hdb3Texts)
            {
                window.draw(bitText);
            }
        }

        // longest palindrome
        text9.setPosition(windowWidth / 1.2, windowHeight / 4);
        window.draw(text9);

        // Draw the vertical dotted lines
        for (const auto &dottedLine : dottedLines)
        {
            window.draw(dottedLine);
        }
        // Display the content
        window.display();
    }
    window.close();
}
