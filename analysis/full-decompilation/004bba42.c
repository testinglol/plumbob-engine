
uint __thiscall FUN_004bba42(int *param_1,int param_2)

{
  int iVar1;
  uint in_EAX;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if (((param_2 != 0) && (in_EAX = FUN_005b8f4a(param_1[6]), (char)in_EAX != '\0')) &&
     ((*param_1 != 0 || ((in_EAX = FUN_004bb700(), (char)in_EAX == '\0' && (*param_1 != 0)))))) {
    iVar1 = param_1[1];
    uVar2 = FUN_004bb9b6();
    iVar4 = 0;
    iVar3 = param_1[1] * 2 + 1;
    if (0 < iVar3) {
      do {
        in_EAX = FUN_005b904f(*(undefined4 *)(*param_1 + iVar4 * 4),uVar2 / (iVar1 * 2 + 1U));
        if ((char)in_EAX == '\0') goto LAB_004bbab5;
        iVar4 = iVar4 + 1;
        iVar3 = param_1[1] * 2 + 1;
      } while (iVar4 < iVar3);
    }
    return CONCAT31((int3)((uint)iVar3 >> 8),1);
  }
LAB_004bbab5:
  return in_EAX & 0xffffff00;
}

