# Line-encoder


Line Encoder is a project that allows users to generate digital signals by providing options for analog or digital input. The program proceeds with line encoding or PCM/DM based on the user's choice. For encoding, various options such as NRZ-L, NRZ-I, Manchester, Differential Manchester, and AMI are provided. If the user selects AMI, additional queries about scrambling preferences and scrambling type are presented.

## Installation

- To install Line Encoder, clone the repository:

```bash
git clone https://github.com/Mayvid0/Line-encoder
```


- Ensure you have the SFML library for C++ installed:

- For macOS: 
```bash
brew install sfml
```

- For Ubuntu: 
```bash
sudo apt-get install libsfml-dev
```

- For Windows:
```bash
Install SFML SDK
```

### After installation, navigate to the project directory:
```bash
cd Line-encoder
```

### Modify the makefile for necessary headers and libraries. For macOS, you might not need to make any changes, but for Linux, find the necessary include paths and libraries using commands like:
```bash
grep -r "sfml" /usr/include
grep -r "sfml" /usr/lib
```

### Similarly for windows , look for the necessary headers and libraries after the installation of sfml

## Update the SFML_DIR_LINUX, SFML_DIR_WINDOWS, or SFML_DIR_MACOS variables in the makefile.

# Build : 
```bash
make
```

# Run the encoder: 
```bash
./openWindow
```

# Usage :
#### The program prompts the user for digital signal generation preferences and offers various encoding techniques. It also processes analog input for PCM/DM, generating digital data that can be fed into line encoding techniques. The output includes the digital data stream, the longest palindrome in the data stream, the produced digital signal, and, in the case of scrambling, the scrambled signal.

# Contributing : 
#### Feel free to contribute to the project. Any contributions, suggestions, or bug reports are welcome.

# License: 
#### This project is released under a free license.

# Contact me :
 Connect with me on [LinkedIn](https://www.linkedin.com/in/divyam-link)  
💬 Ping me on [Telegram](https://t.me/dhdeuiywn)

# Acknowledgments

- [SFML Documentation](https://www.sfml-dev.org/tutorials/2.6)
- [Sound Files](https://www2.cs.uic.edu/~i101/SoundFiles/)
- [ChatGPT](https://www.openai.com/)



