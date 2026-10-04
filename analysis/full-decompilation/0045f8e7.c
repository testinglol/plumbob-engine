
bool __fastcall FUN_0045f8e7(int param_1)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = *(uint *)(param_1 + 0x220);
  bVar2 = uVar1 < *(uint *)(param_1 + 0x224);
  if (bVar2) {
    FUN_0041edc1((uVar1 & 7) * 0x44 + param_1);
    *(int *)(param_1 + 0x220) = *(int *)(param_1 + 0x220) + 1;
  }
  return bVar2;
}

