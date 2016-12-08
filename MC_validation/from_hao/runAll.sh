#!/bin/sh

root -l -b -q 'efficiency.C("PromptPP")' > logPromptPP
root -l -b -q 'efficiency.C("NonPromptPP")' > logNonPromptPP
root -l -b -q 'efficiency.C("PromptPP_new")' > logPromptPP_new
root -l -b -q 'efficiency.C("NonPromptPP_new")' > logNonPromptPP_new

