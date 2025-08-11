<div align="center">

# 🧠 'Distributed' Deep Neural Network

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)
[![C++](https://img.shields.io/badge/C++-17-blue.svg?style=flat&logo=c%2B%2B)](http://www.cplusplus.org/)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat)](http://makeapullrequest.com)
[![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg)](https://github.com/Daniel-Shunom/Distributed_NeuralNet_C-)
[![Stars](kttps://img.shields.io/github/stars/Daniel-Shunom/Distributed_NeuralNet_C-?style=social)](https://github.com/Daniel-Shunom/Distributed_NeuralNet_C-/stargazers)

<br/>

<img src="./Assets/n_net.png" alt="Project Logo" width="200"/>

### *Deep Neural Networks Implementation via Distributed Computing*

<p align="center">
    <b>A sophisticated implementation of distributed neural network architecture leveraging consensus mechanisms for robust and scalable machine learning implementations</b>
</p>

<br/>

[📖 Overview](#-overview) •
[⚡ Quick Start](#-installation) •
[🛠️ Usage](#-usage) •
[🎯 Features](#-features) •
[🤝 Contributing](#-contributing) •
[📧 Contact](#-contact)

---

</div>

## 🌟 Overview/Abstract

Large language models and machine learning algorithms are typically large computing processes that occur often 
in local multithreaded environments. This localization of computing is notoriously resource-intensive for the 
given system and puts a lot of load on the processors and computers involved. For large companies, these issues 
are easier to fix and monitor, given more extensive access to the necessary capital. This is not the same for 
smaller companies that want to build their own models but cannot afford the required infrastructure.

Matrix operations are expensive. What's more expensive is a hundred thousand more, spread across multiple layers
and compute blocks. The big idea here is to distribute these compute operations across a network of participating 
computers across the globe, layer by layer, and return calculated values to be used in the network, effectively 
distributing the network layers and compute blocks across multiple devices.

This project is a **Proof of Concept** and aims to demonstrate a possible cheaper alternative to current model 
development strategies across the globe.


This innovative implementation brings together:

- **Distributed Computing**: Each neural network layer is computed accross the network
- **Consensus Mechanisms**: Validates computed layer packets accross network
- **Scalable Architecture**: Designed for horizontal scaling and high performance
- **Smart Propagation**: Optimized forward propagation with validation checkpoints

<div align="center">
    <img src="https://raw.githubusercontent.com/Daniel-Shunom/Distributed_NeuralNet_C-/main/assets/architecture.png" alt="Architecture Overview" width="600"/>
</div>
