# Billing Structures
Playground for trying out billing system architectures/models using hack.

## Project Notes
There is no ORM/DB hooked up to this project currently. The purpose of this project is to experiment with code and model structures so I wanted to keep it very light weight. This leads to interesting hacks such as using `\rand` to generate fake ID's. Most use cases of `getId` is to show case how a developer would need to explicitly associate models together versus implicit associations handled by parent-child relationships.

For now, assume the system can only operate against a single customer.

## General Notes
Refer to makefile for available commands. Default commands are:

`make check` to verify hack syntax

`make test` to run all tests

`make install` to install composer dependencies

## HH Notes
Refer to blank_hh for installation notes: https://github.com/joshuajlai/blank_hh
