
void __thiscall FUN_004b157a(int *param_1,int param_2)

{
  LPRECT lprc;
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar1 = *(int *)(param_1[0x1a] + 0x74);
  iVar2 = *(int *)(param_1[0x1a] + 0x6c);
  iVar3 = param_2;
  (**(code **)(*param_1 + 0x10))(param_2);
  FUN_0049b229(iVar3);
  iVar3 = param_1[0x1a];
  lprc = (LPRECT)(param_1 + 10);
  lprc->left = *(LONG *)(iVar3 + 0x68);
  param_1[0xb] = *(int *)(iVar3 + 0x6c);
  param_1[0xc] = *(int *)(iVar3 + 0x70);
  param_1[0xd] = *(int *)(iVar3 + 0x74);
  OffsetRect(lprc,-lprc->left,-param_1[0xb]);
  FUN_004a7d36();
  iVar3 = FUN_005caed9();
  if (param_2 == *(int *)(iVar3 + 4)) {
    param_1[0x133] = 0;
    piVar4 = (int *)FUN_005caed9();
    param_1[0x135] = *piVar4;
    iVar3 = FUN_005caed9();
    iVar3 = *(int *)(iVar3 + 4);
    param_1[0x136] = iVar3;
    param_1[0x134] = iVar3 - (iVar1 - iVar2);
  }
  else {
    param_1[0x133] = 0;
    param_1[0x134] = 0;
    param_1[0x135] = 0;
    param_1[0x136] = 0;
  }
  iVar1 = param_1[0xc];
  iVar2 = *(int *)(DAT_006e486c + 0x4c);
  *(undefined4 *)(iVar2 + 0x2a4) = 0;
  *(undefined4 *)(iVar2 + 0x2a8) = 0;
  *(int *)(iVar2 + 0x2ac) = iVar1;
  *(int *)(iVar2 + 0x2b0) = param_2;
  iVar1 = param_1[0xc];
  iVar2 = *(int *)(DAT_006e486c + 0x4c);
  *(undefined4 *)(iVar2 + 0x2b4) = 0;
  *(int *)(iVar2 + 0x2b8) = param_2;
  *(int *)(iVar2 + 700) = iVar1;
  *(int *)(iVar2 + 0x2c0) = param_2 * 2;
  return;
}

