
void FUN_00483fc1(int param_1,ushort param_2,ushort param_3,int param_4)

{
  int iVar1;
  ushort uVar2;
  
  uVar2 = param_2;
  if (*(char *)(param_4 + 0x1c) != '\0') {
    iVar1 = *(int *)(param_4 + 0x34);
    if (iVar1 == -1) goto LAB_00483ff6;
    uVar2 = param_3;
    if (iVar1 != -2) {
      if (iVar1 == -3) {
        return;
      }
      param_3 = (short)iVar1 + param_2;
      goto LAB_00483ff6;
    }
  }
  param_3 = uVar2 + 4;
LAB_00483ff6:
  *(ushort *)(param_1 + 0x4c) = param_3 & 7;
  return;
}

