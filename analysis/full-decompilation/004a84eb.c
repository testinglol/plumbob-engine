
undefined4 __thiscall FUN_004a84eb(int param_1,short param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  uVar3 = DAT_006fe838;
  iVar1 = (int)param_2;
  if (iVar1 < 0xd2) {
    if (iVar1 == 0xd1) {
      return 1;
    }
    if (iVar1 < 0x94) {
      if (iVar1 != 0x93) {
        if (iVar1 == 0x83) {
          (**(code **)(*(int *)(param_1 + -8) + 0x48))();
        }
        else {
          if (iVar1 == 0x84) {
            if (DAT_006e54ac != (int *)0x0) {
              (**(code **)(*DAT_006e54ac + 0x74))(param_3);
              return 1;
            }
            return 1;
          }
          if (iVar1 != 0x85) {
            if (iVar1 == 0x87) {
              iVar1 = FUN_00407498(param_3);
              piVar5 = *(int **)(param_1 + 0x1c0);
              while( true ) {
                if (piVar5 == *(int **)(param_1 + 0x1c4)) {
                  return 1;
                }
                if (*piVar5 == iVar1) break;
                piVar5 = piVar5 + 1;
              }
              if (piVar5 != *(int **)(param_1 + 0x1c4)) {
                FUN_004486a3(piVar5);
                return 1;
              }
              return 1;
            }
            if (iVar1 != 0x92) {
              return 0;
            }
            FUN_004b4472(param_1 + -8,param_3,0x484f5553,0,*(undefined4 *)(DAT_006e486c + 0x44));
            if (*(char *)(param_1 + 0x47) != '\0') {
              FUN_004b1eb5(param_3,0x200);
              FUN_004b2243(param_3,0x400);
              return 1;
            }
            return 1;
          }
        }
        FUN_004b0824();
        return 1;
      }
      FUN_004b44c9(param_1 + -8,param_3,0x484f5553,0,0);
      FUN_004b0542();
      FUN_004a891e();
      FUN_004a891e();
    }
    else {
      if (iVar1 != 0xc3) {
        if (iVar1 == 0xc4) {
          *(bool *)(param_1 + 0x42) = *(char *)(param_1 + 0x42) == '\0';
        }
        else if (iVar1 == 0xc5) {
          *(bool *)(param_1 + 0x43) = *(char *)(param_1 + 0x43) == '\0';
        }
        else if (iVar1 == 0xc6) {
          *(bool *)(param_1 + 0x44) = *(char *)(param_1 + 0x44) == '\0';
        }
        else {
          if (iVar1 != 199) {
            return 0;
          }
          *(bool *)(param_1 + 0x45) = *(char *)(param_1 + 0x45) == '\0';
        }
        goto LAB_004a8661;
      }
      FUN_004a8361(*(char *)(param_1 + 0x40) == '\0');
    }
    iVar1 = *(int *)(param_1 + -8);
  }
  else {
    if (iVar1 < 0xf7) {
      if (iVar1 == 0xf6) {
        (**(code **)(*(int *)(param_1 + -8) + 0x48))();
        *(int *)(param_1 + 0x50) = 0x10 << ((byte)DAT_006f0088 & 0x1f);
        *(int *)(param_1 + 0x54) = 8 << ((byte)DAT_006f0088 & 0x1f);
        *(int *)(param_1 + 0x58) = 8 << ((byte)DAT_006f0088 & 0x1f);
        *(int *)(param_1 + 0x5c) = 4 << ((byte)DAT_006f0088 & 0x1f);
        puVar6 = (undefined4 *)(param_1 + 0x200);
        for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar6 = 0;
          puVar6 = puVar6 + 1;
        }
        FUN_0049eb08();
        *(undefined1 *)(param_1 + 0x46) = 1;
        FUN_004a7da6(DAT_006f0088,1,1);
        FUN_004a8012(DAT_006f008c,1,1);
        FUN_004a82db(*(undefined4 *)(param_1 + 0x10),1);
        *(undefined4 *)(param_1 + 0x168) = 0;
        *(undefined4 *)(param_1 + 0x16c) = 0;
        FUN_004a83dc(DAT_006f0080,DAT_006f0084,1);
        uVar3 = *(undefined4 *)(param_1 + 0x10);
        uVar2 = (uint)*(byte *)(param_1 + 0x40);
        FUN_00540a5b(uVar2,uVar3);
        FUN_005406d1(uVar2,uVar3);
        *(undefined1 *)(param_1 + 0x46) = 1;
        FUN_004aaec9();
        FUN_0044651b();
        return 1;
      }
      iVar4 = iVar1;
      if (iVar1 != 0xe4) {
        if (iVar1 == 0xe7) {
          DAT_006fe838 = DAT_006d6180;
          FUN_005cddcf(param_1 + 0x20);
          DAT_006fe838 = uVar3;
          return 1;
        }
        if (iVar1 < 0xec) {
          return 0;
        }
        if (iVar1 < 0xee) {
          iVar1 = *(int *)(DAT_006e486c + 0x18);
          if (param_2 == 0xec) {
            if ((*(int *)(iVar1 + 0x10) - *(int *)(iVar1 + 0xc) & 0xfffffffcU) != 0) {
              FUN_004934bf();
              return 1;
            }
            return 1;
          }
          if (param_2 == 0xed) {
            if ((*(int *)(iVar1 + 0x1c) - *(int *)(iVar1 + 0x18) & 0xfffffffcU) != 0) {
              FUN_004934fd();
              return 1;
            }
            return 1;
          }
          return 1;
        }
        if (iVar1 == 0xf0) {
          *(undefined1 *)(param_1 + 0x1f8) = 1;
          FUN_0049eb08();
          return 1;
        }
        if (iVar1 != 0xf1) {
          return 0;
        }
        iVar1 = FUN_004670a4(param_3);
        if (iVar1 != 0) {
          FUN_004681f5(1);
          return 1;
        }
        return 1;
      }
LAB_004a8904:
      FUN_004abb9e(CONCAT31((int3)((uint)iVar4 >> 8),*(undefined1 *)(param_1 + 0x1f0)));
      return 1;
    }
    iVar4 = 0;
    if (iVar1 == 0xf7) goto LAB_004a8904;
    if (iVar1 == 0xf9) {
      if (DAT_006e54ac != (int *)0x0) {
        (**(code **)(*DAT_006e54ac + 0x70))(param_3);
        return 1;
      }
      return 1;
    }
    if (iVar1 == 0x105) {
      FUN_004b0824();
      puVar6 = (undefined4 *)(param_1 + 0x200);
      for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      FUN_0049eb08();
      *(undefined1 *)(param_1 + 0x46) = 1;
      uVar8 = 1;
      uVar7 = 1;
      uVar3 = (**(code **)(*(int *)(param_1 + -8) + 0x18))(1,1);
      FUN_004a8012(uVar3,uVar7,uVar8);
      return 1;
    }
    if (iVar1 != 0x3f6) {
      return 0;
    }
LAB_004a8661:
    iVar1 = *(int *)(param_1 + -8);
  }
  (**(code **)(iVar1 + 0x48))();
  return 1;
}

