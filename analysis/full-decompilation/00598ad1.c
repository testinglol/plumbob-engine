
void __fastcall FUN_00598ad1(uint *param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = _rand();
  uVar2 = _rand();
  *param_1 = iVar1 << 0x10 ^ uVar2;
  iVar1 = _rand();
  uVar2 = _rand();
  param_1[1] = iVar1 << 0x10 ^ uVar2;
  return;
}

