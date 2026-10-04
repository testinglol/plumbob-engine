
undefined4 __thiscall
FUN_005d6695(int param_1,undefined4 *param_2,uint param_3,undefined4 param_4,undefined4 param_5)

{
  int *piVar1;
  int *piVar2;
  short sVar3;
  undefined4 uVar4;
  
  sVar3 = (short)((uint)param_5 >> 0x10);
  if (0x204 < param_3) {
    if (param_3 < 0x602) {
      if (param_3 != 0x601) {
        if (param_3 == 0x205) {
          *param_2 = 0xc;
        }
        else if (param_3 == 0x206) {
          *param_2 = 10;
        }
        else {
          if (param_3 != 0x20a) {
            if (param_3 == 0x500) {
              *param_2 = 3;
            }
            else {
              if (param_3 != 0x600) goto LAB_005d685e;
              *param_2 = 1;
            }
            goto LAB_005d6837;
          }
          *param_2 = 0xe;
        }
        goto LAB_005d67fe;
      }
      *param_2 = 2;
    }
    else {
      if (param_3 != 0x700) {
        if (param_3 == 0x800) {
          *param_2 = 0x11;
        }
        else {
          if (param_3 == 0x801) {
            *param_2 = 0x12;
            return 1;
          }
          if (param_3 != 0x802) goto LAB_005d685e;
          *param_2 = 0x13;
        }
LAB_005d6887:
        param_2[1] = param_4;
        return 1;
      }
      *param_2 = 0x10;
    }
LAB_005d6837:
    param_2[1] = param_4;
    param_2[2] = param_5;
    return 1;
  }
  if (param_3 == 0x204) {
    *param_2 = 8;
LAB_005d67fe:
    piVar1 = param_2 + 1;
    piVar2 = param_2 + 2;
    *piVar1 = (int)(short)param_5;
    *piVar2 = (int)sVar3;
    uVar4 = FUN_005d6929(param_4);
    param_2[3] = uVar4;
    if (*piVar1 < 0) {
      *piVar1 = 0;
    }
    else if (*(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x7c) <= *piVar1) {
      *piVar1 = (*(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x7c)) + -1;
    }
    if (*piVar2 < 0) {
      *piVar2 = 0;
    }
    else if (*(int *)(param_1 + 0x88) - *(int *)(param_1 + 0x80) <= *piVar2) {
      *piVar2 = (*(int *)(param_1 + 0x88) - *(int *)(param_1 + 0x80)) + -1;
    }
    return 1;
  }
  if (0x105 < param_3) {
    if (param_3 == 0x200) {
      *param_2 = 0xd;
    }
    else if (param_3 == 0x201) {
      *param_2 = 7;
    }
    else if (param_3 == 0x202) {
      *param_2 = 0xb;
    }
    else {
      if (param_3 != 0x203) {
LAB_005d685e:
        *param_2 = 0;
        return 0;
      }
      *param_2 = 9;
    }
    goto LAB_005d67fe;
  }
  if (param_3 == 0x105) {
LAB_005d6721:
    *param_2 = 6;
  }
  else {
    if (param_3 == 0xa0) {
      *param_2 = 0xf;
      param_2[1] = (int)(short)param_5;
      param_2[2] = (int)sVar3;
      uVar4 = FUN_005d6929(param_4);
      param_2[3] = uVar4;
      return 1;
    }
    if (param_3 != 0x100) {
      if (param_3 == 0x101) goto LAB_005d6721;
      if (param_3 == 0x102) {
        *param_2 = 4;
        goto LAB_005d6887;
      }
      if (param_3 != 0x104) goto LAB_005d685e;
    }
    *param_2 = 5;
  }
  param_2[1] = param_4;
  uVar4 = FUN_005d68de();
  param_2[2] = uVar4;
  return 1;
}

