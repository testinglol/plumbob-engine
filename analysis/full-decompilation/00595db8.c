
void __thiscall FUN_00595db8(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = _rand();
  uVar2 = _rand();
  *(int *)(param_1 + 8) = (int)(iVar1 << 0x10 ^ uVar2) >> 8;
  iVar1 = _rand();
  uVar2 = _rand();
  *(int *)(param_1 + 0xc) = (int)(iVar1 << 0x10 ^ uVar2) >> 8;
  FUN_00595e04((int *)(param_1 + 8),(int *)(param_1 + 0xc),param_2);
  return;
}

