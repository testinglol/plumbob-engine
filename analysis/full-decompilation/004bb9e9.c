
uint __thiscall FUN_004bb9e9(int *param_1,int param_2)

{
  int iVar1;
  uint in_EAX;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if (*(char *)(param_2 + 0x1d) == '\0') {
LAB_004bba3e:
    uVar2 = in_EAX & 0xffffff00;
  }
  else {
    iVar1 = param_1[1];
    uVar2 = FUN_004bb9b6();
    iVar4 = 0;
    iVar3 = param_1[1] * 2 + 1;
    if (0 < iVar3) {
      do {
        in_EAX = FUN_005b9068(*(undefined4 *)(*param_1 + iVar4 * 4),uVar2 / (iVar1 * 2 + 1U));
        if ((char)in_EAX == '\0') goto LAB_004bba3e;
        iVar4 = iVar4 + 1;
        iVar3 = param_1[1] * 2 + 1;
      } while (iVar4 < iVar3);
    }
    uVar2 = CONCAT31((int3)((uint)iVar3 >> 8),1);
  }
  return uVar2;
}

