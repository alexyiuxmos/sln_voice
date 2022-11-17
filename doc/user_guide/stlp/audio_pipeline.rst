.. include:: <isonum.txt>

.. _sln_voice_stlp_ap:

##############
Audio Pipeline
##############

========
Overview
========

The audio pipeline in STLP processes two channel pdm microphone input into a single output channel, intended for use by an ASR engine.

The audio pipeline consists of 4 stages.

.. list-table:: STLP Audio Pipeline
   :widths: 30 100 10 10
   :header-rows: 1
   :align: left

   * - Stage
     - Description
     - Input Channel Count
     - Output Channel Count
   * - 1
     - Acoustic Echo Cancellation (AEC)
     - 2
     - 2
   * - 2
     - Interference Canceller and Voice Activity Detection
     - 2
     - 1
   * - 3
     - Noise Suppression
     - 1
     - 1
   * - 4
     - Automatic Gain Control
     - 1
     - 1

TODO: link to XCORE SDK voice framework documentation
