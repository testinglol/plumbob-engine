
void __fastcall FUN_00422a6e(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 400);
  if (*(int *)(param_1 + 400) == 0) {
    iVar5 = param_1;
  }
  iVar2 = *(int *)(iVar5 + 0x198);
  iVar3 = *(int *)(iVar5 + 0x194);
  iVar4 = *(int *)(iVar5 + 0x19c);
  sVar1 = *(short *)(iVar5 + 0x4c);
  for (; iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x18c)) {
    *(int *)(iVar5 + 0x1a0) = *(int *)(iVar5 + 0x194) - iVar3;
    *(int *)(iVar5 + 0x1a4) = *(int *)(iVar5 + 0x198) - iVar2;
    *(int *)(iVar5 + 0x1a8) = *(int *)(iVar5 + 0x19c) - iVar4;
    FUN_004236d0((int)sVar1,(int *)(iVar5 + 0x1a0),(int *)(iVar5 + 0x1a4));
  }
  return;
}

