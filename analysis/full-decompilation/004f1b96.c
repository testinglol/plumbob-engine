
uint __thiscall FUN_004f1b96(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  char *pcVar7;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_004fadfb(0);
  FUN_0042004f();
  FUN_004d3125();
  *(undefined1 *)(param_1 + 0xf4) = 1;
  FUN_0046dae0(0x20,0);
  local_18 = FUN_0042808b(param_2,param_3);
  FUN_0046dae0(0x20,0);
  *(undefined1 *)(param_1 + 0xf4) = 0;
  if (*(short *)(DAT_006e486c[7] + 0x22) == 0) {
    iVar2 = FUN_0042ba25(param_2);
    if ((((iVar2 == 0) || (*(char *)(param_1 + 0x140) == '\x01')) ||
        (*(char *)(param_1 + 0x141) == '\x01')) || (*(char *)(param_1 + 0x142) == '\x01')) {
      if ((param_2 < 0x15) || (0x1e < param_2)) {
        if ((param_2 < 0x51) || (0x59 < param_2)) {
          if ((((0x27 < param_2) && (param_2 < 0x32)) || (iVar2 = FUN_0042ba25(param_2), iVar2 == 2)
              ) || ((0x5c < param_2 && (param_2 < 100)))) {
            iVar2 = FUN_00425db3(0);
            param_3 = DAT_006e486c[7];
            uVar3 = FUN_004425e2();
            FUN_0046d7b3(uVar3);
            FUN_0046d956();
            FUN_00445d17();
            if (*(char *)(param_1 + 0x140) == '\x01') {
LAB_004f210d:
              FUN_00410ad4(*(undefined4 *)(param_1 + 0x134));
              uVar3 = FUN_004e9918(0);
              FUN_004e9855(uVar3);
              FUN_00425db3(0);
              uVar3 = FUN_004e9918(0);
              iVar2 = FUN_004e9744(uVar3);
              local_8 = 0;
              if (iVar2 != 0) {
                param_3 = FUN_00425db3((int)*(short *)(iVar2 + 0x606));
                local_8 = FUN_0042a8e3(*(undefined2 *)(iVar2 + 0x5ca));
                if (param_3 != 0) {
                  FUN_0046d9f8(*(undefined4 *)(param_3 + 0x118));
                }
              }
              FUN_004cee86(0x4000);
              if (local_8 != 0) {
                param_3 = -1;
                local_24 = 0;
                local_20 = 0;
                local_1c = CONCAT22(local_1c._2_2_,1);
                FUN_0041f69e(2,&param_3,7);
                if ((short)param_3 != -1) {
                  FUN_0041f6fd(param_3,&local_24);
                  local_8 = local_1c;
                  FUN_0041f56d(param_3,0xffffffff);
                  param_3 = -1;
                  FUN_0041f69e(2,&param_3,8);
                  if ((short)param_3 != -1) {
                    FUN_0041f6fd(param_3,&local_24);
                    local_c = local_1c;
                    FUN_0041f56d(param_3,0xffffffff);
                    FUN_0046d98b((int)(short)local_8,(int)(short)local_c);
                  }
                }
              }
              if (param_2 == 99) {
                FUN_0046d98b(0xc,0);
              }
              *(undefined1 *)(param_1 + 0x140) = 0;
            }
            else {
              if (*(char *)(param_1 + 0x141) != '\x01') {
                FUN_0046dae0(0x20,1);
                *(undefined4 *)(iVar2 + 0x118) = 0;
                FUN_0046d9f8(0);
                FUN_004cee86(0x4000);
                if ((0x27 < param_2) && (param_2 < 0x32)) goto LAB_004f1cbb;
                goto LAB_004f2490;
              }
              if (*(char *)(param_1 + 0x140) == '\x01') goto LAB_004f210d;
            }
            if (*(char *)(param_1 + 0x141) == '\x01') {
              iVar2 = FUN_00425db3((int)*(short *)(param_1 + 0x138));
              local_c = iVar2;
              if (iVar2 != 0) {
                if ((0x27 < param_2) && (param_2 < 0x32)) {
                  *(int *)(iVar2 + 0x13c) = param_2;
                  FUN_00425316(DAT_006e486c[0x11]);
                }
                *(int *)(*DAT_006e486c + 0x10) = iVar2;
                FUN_0046dae0(9,*(undefined4 *)(iVar2 + 0x10c));
                FUN_0046d9f8(*(undefined4 *)(iVar2 + 0x118));
                FUN_004cee86(0x4000);
                local_8 = 0;
                iVar2 = FUN_004102e1();
                if (0 < iVar2) {
                  do {
                    puVar5 = (undefined4 *)FUN_004102ab(local_8);
                    uVar3 = FUN_004e988f(*puVar5);
                    FUN_004e9855(uVar3);
                    if (local_8 == 0) {
                      uVar3 = FUN_004e9918(0);
                      iVar2 = FUN_004e9744(uVar3);
                      iVar2 = FUN_0042a8e3(*(undefined2 *)(iVar2 + 0x5ca));
                      if (iVar2 != 0) {
                        param_3 = -1;
                        local_24 = 0;
                        local_20 = 0;
                        local_1c = CONCAT22(local_1c._2_2_,1);
                        FUN_0041f69e(2,&param_3,7);
                        if ((short)param_3 != -1) {
                          FUN_0041f6fd(param_3,&local_24);
                          local_14 = local_1c;
                          FUN_0041f56d(param_3,0xffffffff);
                          param_3 = -1;
                          FUN_0041f69e(2,&param_3,8);
                          if ((short)param_3 != -1) {
                            FUN_0041f6fd(param_3,&local_24);
                            local_10 = local_1c;
                            FUN_0041f56d(param_3,0xffffffff);
                            FUN_0046d98b((int)(short)local_14,(int)(short)local_10);
                          }
                        }
                      }
                    }
                    local_8 = local_8 + 1;
                    iVar2 = FUN_004102e1();
                  } while (local_8 < iVar2);
                }
              }
              if ((0x27 < param_2) && (param_2 < 0x32)) {
                FUN_004f277c();
              }
            }
            goto LAB_004f2484;
          }
        }
        else {
          iVar2 = FUN_00425db3(0);
          param_3 = DAT_006e486c[7];
          uVar3 = FUN_004425e2();
          FUN_0046d7b3(uVar3);
          FUN_0046d956();
          if (*(char *)(param_1 + 0x142) != '\x01') goto LAB_004f1ff5;
          FUN_00410ad4(*(undefined4 *)(param_1 + 0x134));
          uVar3 = FUN_004e9918(0);
          FUN_004e9855(uVar3);
          FUN_00425db3(0);
          uVar3 = FUN_004e9918(0);
          iVar2 = FUN_004e9744(uVar3);
          iVar4 = FUN_00425db3((int)*(short *)(iVar2 + 0x606));
          FUN_0046d9f8(*(undefined4 *)(iVar4 + 0x118));
          FUN_004cee86(0x4000);
          iVar2 = FUN_0042a8e3(*(undefined2 *)(iVar2 + 0x5ca));
          if (iVar2 != 0) {
            param_3 = -1;
            local_24 = 0;
            local_20 = 0;
            local_1c = CONCAT22(local_1c._2_2_,1);
            FUN_0041f69e(2,&param_3,7);
            if ((short)param_3 != -1) {
              FUN_0041f6fd(param_3,&local_24);
              local_8 = local_1c;
              FUN_0041f56d(param_3,0xffffffff);
              param_3 = -1;
              FUN_0041f69e(2,&param_3,8);
              if ((short)param_3 != -1) {
                FUN_0041f6fd(param_3,&local_24);
                local_c = local_1c;
                FUN_0041f56d(param_3,0xffffffff);
                FUN_0046d98b((int)(short)local_8,(int)(short)local_c);
              }
            }
          }
          *(undefined1 *)(param_1 + 0x142) = 0;
        }
      }
      else {
        iVar2 = FUN_00425db3(0);
        param_3 = DAT_006e486c[7];
        uVar3 = FUN_004425e2();
        FUN_0046d7b3(uVar3);
        FUN_0046d956();
        if (*(char *)(param_1 + 0x140) == '\x01') {
          FUN_00410ad4(*(undefined4 *)(param_1 + 0x134));
          uVar3 = FUN_004e9918(0);
          FUN_004e9855(uVar3);
          FUN_00425db3(0);
          uVar3 = FUN_004e9918(0);
          iVar2 = FUN_004e9744(uVar3);
          iVar4 = FUN_00425db3((int)*(short *)(iVar2 + 0x606));
          FUN_0046d9f8(*(undefined4 *)(iVar4 + 0x118));
          FUN_004cee86(0x4000);
          iVar2 = FUN_0042a8e3(*(undefined2 *)(iVar2 + 0x5ca));
          if (iVar2 != 0) {
            param_3 = -1;
            local_24 = 0;
            local_20 = 0;
            local_1c = CONCAT22(local_1c._2_2_,1);
            FUN_0041f69e(2,&param_3,7);
            if ((short)param_3 != -1) {
              FUN_0041f6fd(param_3,&local_24);
              local_8 = local_1c;
              FUN_0041f56d(param_3,0xffffffff);
              param_3 = -1;
              FUN_0041f69e(2,&param_3,8);
              if ((short)param_3 != -1) {
                FUN_0041f6fd(param_3,&local_24);
                local_c = local_1c;
                FUN_0041f56d(param_3,0xffffffff);
                FUN_0046d98b((int)(short)local_8,(int)(short)local_c);
              }
            }
          }
          *(undefined1 *)(param_1 + 0x140) = 0;
        }
        else {
LAB_004f1ff5:
          FUN_0046dae0(0x20,1);
          *(undefined4 *)(iVar2 + 0x118) = 0;
          FUN_0046d9f8(0);
          FUN_004cee86(0x4000);
        }
      }
    }
    else {
      iVar2 = FUN_00425db3(0);
      param_3 = DAT_006e486c[7];
      uVar3 = FUN_004425e2();
      FUN_0046d7b3(uVar3);
      FUN_0046d956();
      FUN_0046dae0(0x20,1);
      *(undefined4 *)(iVar2 + 0x118) = 0;
      FUN_0046d9f8(0);
      FUN_004cee86(0x4000);
LAB_004f1cbb:
      FUN_00445d17();
      FUN_0046d98b(10,0);
    }
  }
  else {
    iVar2 = FUN_0042ba25(param_2);
    if (iVar2 == 1) {
      iVar2 = *(int *)(*DAT_006e486c + 0x10);
      if (iVar2 != 0) {
        if (*(int *)(iVar2 + 0x13c) != 0) {
          *(undefined4 *)(iVar2 + 0x13c) = 0;
          FUN_00425316(DAT_006e486c[0x11]);
        }
        FUN_0046d9f8(*(undefined4 *)(iVar2 + 0x118));
        FUN_004cee86(0x4000);
      }
LAB_004f2484:
      *(undefined1 *)(param_1 + 0x140) = 0;
      *(undefined1 *)(param_1 + 0x141) = 0;
    }
  }
LAB_004f2490:
  iVar2 = FUN_004e99a9();
  if (iVar2 != -1) {
    uVar3 = FUN_004e99a9();
    iVar2 = FUN_004e9744(uVar3);
    if (*(short *)(iVar2 + 0x606) != 0) goto LAB_004f24bd;
  }
  uVar3 = FUN_004e9918(0);
  FUN_004e99d7(uVar3);
LAB_004f24bd:
  if (local_18 == 0) {
    if (((param_2 == 0x1c) || (param_2 == 0x1d)) || ((0x2d < param_2 && (param_2 < 0x31)))) {
      pcVar7 = s_setambience_beach_006cabec;
    }
    else if (((param_2 < 0x15) || (0x1e < param_2)) && ((param_2 < 0x2b || (0x2d < param_2)))) {
      if ((param_2 < 0x5a) || (0x5c < param_2)) {
        pcVar7 = s_setambience_backyard_006cac00;
      }
      else {
        pcVar7 = s_setambience_magictown_006cac18;
      }
    }
    else {
      pcVar7 = s_setambience_park_006cac30;
    }
    FUN_0057a14d(pcVar7);
    *(undefined1 *)(param_1 + 0xf7) = 0;
    FUN_004cebbc(CONCAT31((int3)((uint)DAT_006e486c[7] >> 8),*(short *)(DAT_006e486c[7] + 0x50) == 1
                         ));
    iVar2 = FUN_0042ba25(param_2);
    if ((iVar2 == 2) || ((0x5c < param_2 && (param_2 < 100)))) {
      uVar3 = CONCAT31((int3)((uint)DAT_006e486c[7] >> 8),*(short *)(DAT_006e486c[7] + 0x50) == 0);
    }
    else if ((*(short *)(DAT_006e486c[7] + 0x50) == 0) &&
            (*(int *)(*(int *)(*DAT_006e486c + 0x10) + 0x10c) == 0)) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
    FUN_004cebe6(uVar3);
    FUN_004cffa9(CONCAT31((int3)((uint)DAT_006e486c[7] >> 8),*(short *)(DAT_006e486c[7] + 0x50) == 1
                         ));
    if (*(short *)(DAT_006e486c[7] + 0x50) == 1) {
      FUN_004cebf8(1,0);
      FUN_004cefe5(1);
      FUN_004cee86(0x4000);
    }
    else {
      FUN_004ce5c1();
    }
    cVar1 = FUN_0043e2dc();
    if (cVar1 != '\0') {
      (**(code **)(*(int *)(param_1 + 0x48) + 0x2c))(&DAT_006f2830,&DAT_006f2820,0,0);
    }
    FUN_004fc1e5();
    FUN_004f649a(param_2);
    iVar2 = DAT_006e486c[7];
    *(undefined1 *)(iVar2 + 0xe1) = 0;
    uVar6 = CONCAT31((int3)((uint)iVar2 >> 8),1);
  }
  else {
    uVar6 = (**(code **)(*(int *)(param_1 + 0x48) + 0x2c))(&DAT_006f2810,&DAT_006f2800,0,0);
    uVar6 = uVar6 & 0xffffff00;
  }
  return uVar6;
}

