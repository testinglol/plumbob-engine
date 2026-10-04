
uint FUN_009d1f90(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  undefined1 local_18 [4];
  int local_14;
  int local_10;
  int *local_c;
  int *local_8;
  
  piVar5 = (int *)FUN_009daa10(local_18,param_1,param_2,&DAT_00cb8a00,0x3b8);
  if (piVar5 != param_3) {
    iVar1 = piVar5[1];
    *param_3 = *piVar5;
    param_3[1] = iVar1;
    *piVar5 = 0;
    piVar5[1] = 0;
  }
  if (*param_3 != 0 || param_3[1] != 0) {
    piVar5 = (int *)FUN_009daa10(local_18,param_1,param_2,&DAT_00cb8438,0x48c);
    if (piVar5 != param_3 + 2) {
      iVar1 = piVar5[1];
      param_3[2] = *piVar5;
      param_3[3] = iVar1;
      *piVar5 = 0;
      piVar5[1] = 0;
    }
    if (param_3[2] != 0 || param_3[3] != 0) {
      local_8 = param_3 + 4;
      piVar5 = (int *)FUN_009daa10(local_18,param_1,param_2,&DAT_00cbd528,0x44c);
      if (piVar5 != param_3 + 4) {
        iVar1 = piVar5[1];
        param_3[4] = *piVar5;
        param_3[5] = iVar1;
        *piVar5 = 0;
        piVar5[1] = 0;
      }
      if (param_3[4] != 0 || param_3[5] != 0) {
        piVar5 = (int *)FUN_009daa10(local_18,param_1,param_2,&DAT_00cbe6f8,0x418);
        if (piVar5 != param_3 + 6) {
          iVar1 = piVar5[1];
          param_3[6] = *piVar5;
          param_3[7] = iVar1;
          *piVar5 = 0;
          piVar5[1] = 0;
        }
        if (param_3[6] != 0 || param_3[7] != 0) {
          piVar5 = (int *)FUN_009daa10(local_18,param_1,param_2,&DAT_00cc2360,0x4b0);
          if (piVar5 != param_3 + 8) {
            iVar1 = piVar5[1];
            param_3[8] = *piVar5;
            param_3[9] = iVar1;
            *piVar5 = 0;
            piVar5[1] = 0;
          }
          if (param_3[8] != 0 || param_3[9] != 0) {
            piVar5 = (int *)FUN_009daa10(local_18,param_1,param_2,&DAT_00cc1d58,0x604);
            if (piVar5 != param_3 + 10) {
              iVar1 = piVar5[1];
              param_3[10] = *piVar5;
              param_3[0xb] = iVar1;
              *piVar5 = 0;
              piVar5[1] = 0;
            }
            if (param_3[10] != 0 || param_3[0xb] != 0) {
              piVar5 = (int *)FUN_009daa10(local_18,param_1,param_2,&DAT_00cc33d0,0x514);
              if (piVar5 != param_3 + 0xc) {
                iVar1 = piVar5[1];
                param_3[0xc] = *piVar5;
                param_3[0xd] = iVar1;
                *piVar5 = 0;
                piVar5[1] = 0;
              }
              if (param_3[0xc] != 0 || param_3[0xd] != 0) {
                piVar5 = (int *)FUN_009daa10(local_18,param_1,param_2,&DAT_00cbb548,0x14a8);
                if (piVar5 != param_3 + 0xe) {
                  iVar1 = piVar5[1];
                  param_3[0xe] = *piVar5;
                  param_3[0xf] = iVar1;
                  *piVar5 = 0;
                  piVar5[1] = 0;
                }
                if (param_3[0xe] != 0 || param_3[0xf] != 0) {
                  piVar5 = (int *)FUN_009daa10(local_18,param_1,param_2,&DAT_00cbdf28,0x620);
                  if (piVar5 != param_3 + 0x10) {
                    iVar1 = piVar5[1];
                    param_3[0x10] = *piVar5;
                    param_3[0x11] = iVar1;
                    *piVar5 = 0;
                    piVar5[1] = 0;
                  }
                  if (param_3[0x10] != 0 || param_3[0x11] != 0) {
                    piVar5 = (int *)FUN_009daa10(local_18,param_1,param_2,&DAT_00cb9ec0,0x598);
                    if (piVar5 != param_3 + 0x12) {
                      iVar1 = piVar5[1];
                      param_3[0x12] = *piVar5;
                      param_3[0x13] = iVar1;
                      *piVar5 = 0;
                      piVar5[1] = 0;
                    }
                    if (param_3[0x12] != 0 || param_3[0x13] != 0) {
                      piVar5 = (int *)FUN_009daa10(local_18,param_1,param_2,&DAT_00cbcea8,0x448);
                      if (piVar5 != param_3 + 0x14) {
                        iVar1 = piVar5[1];
                        param_3[0x14] = *piVar5;
                        param_3[0x15] = iVar1;
                        *piVar5 = 0;
                        piVar5[1] = 0;
                      }
                      if (param_3[0x14] != 0 || param_3[0x15] != 0) {
                        piVar5 = (int *)FUN_009daa10(local_18,param_1,param_2,&DAT_00cb7dc0,0x4ac);
                        if (piVar5 != param_3 + 0x16) {
                          iVar1 = piVar5[1];
                          param_3[0x16] = *piVar5;
                          param_3[0x17] = iVar1;
                          *piVar5 = 0;
                          piVar5[1] = 0;
                        }
                        if (param_3[0x16] != 0 || param_3[0x17] != 0) {
                          piVar5 = (int *)FUN_009daa10(local_18,param_1,param_2,&DAT_00cb88c8,0x138)
                          ;
                          if (piVar5 != param_3 + 0x18) {
                            iVar1 = piVar5[1];
                            param_3[0x18] = *piVar5;
                            param_3[0x19] = iVar1;
                            *piVar5 = 0;
                            piVar5[1] = 0;
                          }
                          if (param_3[0x18] != 0 || param_3[0x19] != 0) {
                            piVar5 = (int *)FUN_009daa10(local_18,param_1,param_2,&DAT_00cb8270,
                                                         0x1c8);
                            if (piVar5 != param_3 + 0x1a) {
                              iVar1 = piVar5[1];
                              param_3[0x1a] = *piVar5;
                              param_3[0x1b] = iVar1;
                              *piVar5 = 0;
                              piVar5[1] = 0;
                            }
                            if (param_3[0x1a] != 0 || param_3[0x1b] != 0) {
                              piVar5 = (int *)FUN_009daa10(local_18,param_1,param_2,&DAT_00cbd2f0,
                                                           0x234);
                              if (piVar5 != param_3 + 0x1c) {
                                iVar1 = piVar5[1];
                                param_3[0x1c] = *piVar5;
                                param_3[0x1d] = iVar1;
                                *piVar5 = 0;
                                piVar5[1] = 0;
                              }
                              if (param_3[0x1c] != 0 || param_3[0x1d] != 0) {
                                piVar5 = (int *)FUN_009daa10(local_18,param_1,param_2,&DAT_00cbe548,
                                                             0x1b0);
                                if (piVar5 != param_3 + 0x1e) {
                                  iVar1 = piVar5[1];
                                  param_3[0x1e] = *piVar5;
                                  param_3[0x1f] = iVar1;
                                  *piVar5 = 0;
                                  piVar5[1] = 0;
                                }
                                if (param_3[0x1e] != 0 || param_3[0x1f] != 0) {
                                  piVar5 = (int *)FUN_009daa10(local_18,param_1,param_2,
                                                               &DAT_00cc0a78,0x4ec);
                                  if (piVar5 != param_3 + 0x20) {
                                    iVar1 = piVar5[1];
                                    param_3[0x20] = *piVar5;
                                    param_3[0x21] = iVar1;
                                    *piVar5 = 0;
                                    piVar5[1] = 0;
                                  }
                                  if (param_3[0x20] != 0 || param_3[0x21] != 0) {
                                    piVar5 = (int *)FUN_009daa10(local_18,param_1,param_2,
                                                                 &DAT_00cc0f68,0x7e8);
                                    if (piVar5 != param_3 + 0x22) {
                                      iVar1 = piVar5[1];
                                      param_3[0x22] = *piVar5;
                                      param_3[0x23] = iVar1;
                                      *piVar5 = 0;
                                      piVar5[1] = 0;
                                    }
                                    if (param_3[0x22] != 0 || param_3[0x23] != 0) {
                                      piVar5 = (int *)FUN_009daa10(local_18,param_1,param_2,
                                                                   &DAT_00cc1750,0x604);
                                      if (piVar5 != param_3 + 0x24) {
                                        iVar1 = piVar5[1];
                                        param_3[0x24] = *piVar5;
                                        param_3[0x25] = iVar1;
                                        *piVar5 = 0;
                                        piVar5[1] = 0;
                                      }
                                      if (param_3[0x24] != 0 || param_3[0x25] != 0) {
                                        local_c = param_3 + 0x26;
                                        piVar5 = (int *)FUN_009daa10(local_18,param_1,param_2,
                                                                     &DAT_00cbeb10,0x864);
                                        if (piVar5 != param_3 + 0x26) {
                                          iVar1 = piVar5[1];
                                          param_3[0x26] = *piVar5;
                                          param_3[0x27] = iVar1;
                                          *piVar5 = 0;
                                          piVar5[1] = 0;
                                        }
                                        if (param_3[0x26] != 0 || param_3[0x27] != 0) {
                                          piVar5 = (int *)FUN_009daa10(local_18,param_1,param_2,
                                                                       &DAT_00cbf378,0xa08);
                                          if (piVar5 != param_3 + 0x28) {
                                            iVar1 = piVar5[1];
                                            param_3[0x28] = *piVar5;
                                            param_3[0x29] = iVar1;
                                            *piVar5 = 0;
                                            piVar5[1] = 0;
                                          }
                                          if (param_3[0x28] != 0 || param_3[0x29] != 0) {
                                            piVar5 = (int *)FUN_009daa10(local_18,param_1,param_2,
                                                                         &DAT_00cbfd80,0x3c8);
                                            if (piVar5 != param_3 + 0x2a) {
                                              iVar1 = piVar5[1];
                                              param_3[0x2a] = *piVar5;
                                              param_3[0x2b] = iVar1;
                                              *piVar5 = 0;
                                              piVar5[1] = 0;
                                            }
                                            if (param_3[0x2a] != 0 || param_3[0x2b] != 0) {
                                              piVar5 = (int *)FUN_009daa10(local_18,param_1,param_2,
                                                                           &DAT_00cc0148,0x4e0);
                                              if (piVar5 != param_3 + 0x2c) {
                                                iVar1 = piVar5[1];
                                                param_3[0x2c] = *piVar5;
                                                param_3[0x2d] = iVar1;
                                                *piVar5 = 0;
                                                piVar5[1] = 0;
                                              }
                                              if (param_3[0x2c] != 0 || param_3[0x2d] != 0) {
                                                piVar5 = (int *)FUN_009daa10(local_18,param_1,
                                                                             param_2,&DAT_00cc0628,
                                                                             0x450);
                                                if (piVar5 != param_3 + 0x2e) {
                                                  iVar1 = piVar5[1];
                                                  param_3[0x2e] = *piVar5;
                                                  param_3[0x2f] = iVar1;
                                                  *piVar5 = 0;
                                                  piVar5[1] = 0;
                                                }
                                                if (param_3[0x2e] != 0 || param_3[0x2f] != 0) {
                                                  piVar5 = (int *)FUN_009daa10(local_18,param_1,
                                                                               param_2,&DAT_00cc2810
                                                                               ,0xbc0);
                                                  if (piVar5 != param_3 + 0x30) {
                                                    iVar1 = piVar5[1];
                                                    param_3[0x30] = *piVar5;
                                                    param_3[0x31] = iVar1;
                                                    *piVar5 = 0;
                                                    piVar5[1] = 0;
                                                  }
                                                  if (param_3[0x30] != 0 || param_3[0x31] != 0) {
                                                    piVar5 = (int *)FUN_009daa10(local_18,param_1,
                                                                                 param_2,&
                                                  DAT_00cbaee8,0x3ac);
                                                  if (piVar5 != param_3 + 0x32) {
                                                    iVar1 = piVar5[1];
                                                    param_3[0x32] = *piVar5;
                                                    param_3[0x33] = iVar1;
                                                    *piVar5 = 0;
                                                    piVar5[1] = 0;
                                                  }
                                                  if (param_3[0x32] != 0 || param_3[0x33] != 0) {
                                                    piVar5 = (int *)FUN_009daa10(local_18,param_1,
                                                                                 param_2,&
                                                  DAT_00cbb298,0x2b0);
                                                  if (piVar5 != param_3 + 0x34) {
                                                    iVar1 = piVar5[1];
                                                    param_3[0x34] = *piVar5;
                                                    param_3[0x35] = iVar1;
                                                    *piVar5 = 0;
                                                    piVar5[1] = 0;
                                                  }
                                                  if (param_3[0x34] != 0 || param_3[0x35] != 0) {
                                                    piVar5 = (int *)FUN_009daa10(local_18,param_1,
                                                                                 param_2,&
                                                  DAT_00cbd978,0x5b0);
                                                  if (piVar5 != param_3 + 0x36) {
                                                    iVar1 = piVar5[1];
                                                    param_3[0x36] = *piVar5;
                                                    param_3[0x37] = iVar1;
                                                    *piVar5 = 0;
                                                    piVar5[1] = 0;
                                                  }
                                                  if (param_3[0x36] != 0 || param_3[0x37] != 0) {
                                                    piVar5 = (int *)FUN_009daa10(local_18,param_1,
                                                                                 param_2,&
                                                  DAT_00cb96b0,0x810);
                                                  if (piVar5 != param_3 + 0x38) {
                                                    iVar1 = piVar5[1];
                                                    param_3[0x38] = *piVar5;
                                                    param_3[0x39] = iVar1;
                                                    *piVar5 = 0;
                                                    piVar5[1] = 0;
                                                  }
                                                  if (param_3[0x38] != 0 || param_3[0x39] != 0) {
                                                    piVar5 = (int *)FUN_009daa10(local_18,param_1,
                                                                                 param_2,&
                                                  DAT_00cb8db8,0x8f4);
                                                  if (piVar5 != param_3 + 0x3a) {
                                                    iVar1 = piVar5[1];
                                                    param_3[0x3a] = *piVar5;
                                                    param_3[0x3b] = iVar1;
                                                    *piVar5 = 0;
                                                    piVar5[1] = 0;
                                                  }
                                                  if (param_3[0x3a] != 0 || param_3[0x3b] != 0) {
                                                    piVar5 = (int *)FUN_009daa10(local_18,param_1,
                                                                                 param_2,&
                                                  DAT_00cbc9f0,0x4b8);
                                                  if (piVar5 != param_3 + 0x3c) {
                                                    iVar1 = piVar5[1];
                                                    param_3[0x3c] = *piVar5;
                                                    param_3[0x3d] = iVar1;
                                                    *piVar5 = 0;
                                                    piVar5[1] = 0;
                                                  }
                                                  if (param_3[0x3c] != 0 || param_3[0x3d] != 0) {
                                                    piVar5 = (int *)FUN_009daa10(local_18,param_1,
                                                                                 param_2,&
                                                  DAT_00cb7210,0xbb0);
                                                  if (piVar5 != param_3 + 0x3e) {
                                                    iVar1 = piVar5[1];
                                                    param_3[0x3e] = *piVar5;
                                                    param_3[0x3f] = iVar1;
                                                    *piVar5 = 0;
                                                    piVar5[1] = 0;
                                                  }
                                                  if (param_3[0x3e] != 0 || param_3[0x3f] != 0) {
                                                    piVar5 = (int *)FUN_009daa10(local_18,param_1,
                                                                                 param_2,&
                                                  DAT_00cba458,0xa8c);
                                                  if (piVar5 != param_3 + 0x40) {
                                                    iVar1 = piVar5[1];
                                                    param_3[0x40] = *piVar5;
                                                    param_3[0x41] = iVar1;
                                                    *piVar5 = 0;
                                                    piVar5[1] = 0;
                                                  }
                                                  local_10 = param_3[0x40];
                                                  local_14 = param_3[0x41];
                                                  if (local_10 != 0 || local_14 != 0) {
                                                    iVar1 = param_3[8];
                                                    iVar2 = param_3[9];
                                                    iVar3 = *local_8;
                                                    iVar4 = local_8[1];
                                                    param_3[0x42] = *param_3;
                                                    param_3[0x43] = param_3[1];
                                                    param_3[0x44] = param_3[0x18];
                                                    param_3[0x45] = param_3[0x19];
                                                    param_3[0x46] = param_3[2];
                                                    param_3[0x47] = param_3[3];
                                                    param_3[0x48] = param_3[0x1a];
                                                    param_3[0x49] = param_3[0x1b];
                                                    param_3[0x4a] = iVar3;
                                                    param_3[0x4b] = iVar4;
                                                    param_3[0x4c] = param_3[0x1c];
                                                    param_3[0x4d] = param_3[0x1d];
                                                    param_3[0x4e] = param_3[6];
                                                    param_3[0x4f] = param_3[7];
                                                    param_3[0x50] = param_3[0x1e];
                                                    param_3[0x51] = param_3[0x1f];
                                                    param_3[0x52] = iVar1;
                                                    param_3[0x53] = iVar2;
                                                    param_3[0x54] = param_3[0x20];
                                                    param_3[0x55] = param_3[0x21];
                                                    param_3[0x56] = iVar1;
                                                    param_3[0x57] = iVar2;
                                                    param_3[0x58] = param_3[0x22];
                                                    param_3[0x59] = param_3[0x23];
                                                    iVar3 = *local_c;
                                                    iVar4 = local_c[1];
                                                    param_3[0x5a] = iVar1;
                                                    param_3[0x5b] = iVar2;
                                                    param_3[0x5c] = param_3[0x24];
                                                    param_3[0x5d] = param_3[0x25];
                                                    param_3[0x5e] = param_3[10];
                                                    param_3[0x5f] = param_3[0xb];
                                                    param_3[0x60] = iVar3;
                                                    param_3[0x61] = iVar4;
                                                    param_3[0x62] = param_3[10];
                                                    param_3[99] = param_3[0xb];
                                                    param_3[100] = param_3[0x28];
                                                    param_3[0x65] = param_3[0x29];
                                                    param_3[0x66] = iVar1;
                                                    param_3[0x67] = iVar2;
                                                    param_3[0x68] = param_3[0x2a];
                                                    param_3[0x69] = param_3[0x2b];
                                                    param_3[0x6a] = iVar1;
                                                    param_3[0x6b] = iVar2;
                                                    param_3[0x6c] = param_3[0x2c];
                                                    param_3[0x6d] = param_3[0x2d];
                                                    param_3[0x6e] = iVar1;
                                                    param_3[0x6f] = iVar2;
                                                    param_3[0x70] = param_3[0x2e];
                                                    param_3[0x71] = param_3[0x2f];
                                                    param_3[0x72] = param_3[0xc];
                                                    param_3[0x73] = param_3[0xd];
                                                    param_3[0x74] = param_3[0x30];
                                                    param_3[0x75] = param_3[0x31];
                                                    param_3[0x76] = param_3[0xe];
                                                    param_3[0x77] = param_3[0xf];
                                                    param_3[0x78] = param_3[0x32];
                                                    param_3[0x79] = param_3[0x33];
                                                    param_3[0x7a] = param_3[0xe];
                                                    param_3[0x7b] = param_3[0xf];
                                                    param_3[0x7c] = param_3[0x34];
                                                    param_3[0x7d] = param_3[0x35];
                                                    param_3[0x7e] = param_3[0x10];
                                                    param_3[0x7f] = param_3[0x11];
                                                    param_3[0x80] = param_3[0x36];
                                                    param_3[0x81] = param_3[0x37];
                                                    param_3[0x82] = param_3[0x12];
                                                    param_3[0x83] = param_3[0x13];
                                                    param_3[0x84] = param_3[0x38];
                                                    param_3[0x85] = param_3[0x39];
                                                    param_3[0x86] = param_3[0x12];
                                                    param_3[0x87] = param_3[0x13];
                                                    param_3[0x88] = param_3[0x3a];
                                                    param_3[0x89] = param_3[0x3b];
                                                    param_3[0x8a] = param_3[0x14];
                                                    param_3[0x8b] = param_3[0x15];
                                                    param_3[0x8c] = param_3[0x3c];
                                                    param_3[0x8d] = param_3[0x3d];
                                                    param_3[0x8e] = param_3[0x16];
                                                    param_3[0x8f] = param_3[0x17];
                                                    param_3[0x90] = param_3[0x3e];
                                                    param_3[0x91] = param_3[0x3f];
                                                    param_3[0x92] = param_3[4];
                                                    param_3[0x93] = param_3[5];
                                                    param_3[0x94] = local_10;
                                                    param_3[0x95] = local_14;
                                                    return CONCAT31((int3)((uint)local_14 >> 8),1);
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  uVar6 = FUN_009d2c70(param_1,param_2,param_3);
  return uVar6 & 0xffffff00;
}

