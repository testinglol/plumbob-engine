
int __fastcall FUN_00574d13(int param_1)

{
  int iVar1;
  int iVar2;
  
  (**(code **)(*(int *)(param_1 + 0x128) + 4))();
  iVar1 = *(int *)(param_1 + 0x30);
  iVar2 = *(int *)(param_1 + 0x2c);
  (**(code **)(*(int *)(param_1 + 0x128) + 8))();
  return iVar1 - iVar2 >> 2;
}

