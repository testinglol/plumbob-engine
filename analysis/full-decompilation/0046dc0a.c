
void __thiscall FUN_0046dc0a(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int local_10 [3];
  
  local_10[0] = param_1 + 0xe4;
  local_10[2] = param_1 + 0x184;
  local_10[1] = param_1 + 0x104;
  iVar3 = 0;
  do {
    iVar2 = 0;
    piVar4 = local_10;
    iVar5 = 3;
    do {
      iVar1 = *piVar4;
      piVar4 = piVar4 + 1;
      iVar2 = iVar2 + *(int *)(iVar1 + iVar3);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    *(int *)(iVar3 + param_2) = iVar2;
    iVar3 = iVar3 + 4;
  } while (iVar3 < 0x20);
  return;
}

