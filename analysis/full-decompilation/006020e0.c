
undefined4 __fastcall FUN_006020e0(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)((-(uint)(param_1 != 0) & param_1 + 0x10U) + 4);
  (**(code **)(*piVar1 + 4))();
  (**(code **)(*piVar1 + 8))();
  return 1;
}

