
int __fastcall FUN_0049e2f6(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = *(int *)(param_1 + 0x94);
  iVar2 = *(int *)(param_1 + 0x90);
  uVar3 = FUN_0046f556();
  uVar3 = uVar3 % ((iVar1 - iVar2) + 1U);
  if (*(char *)(param_1 + 0x98) != '\0') {
    uVar4 = FUN_0046f556();
    if ((uVar4 & 1) != 0) {
      uVar3 = -uVar3;
    }
  }
  return *(int *)(param_1 + 0x90) + uVar3;
}

