
void __fastcall FUN_0060204a(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x44))();
  if (iVar1 == 0) {
    do {
      (**(code **)(param_1[0xb] + 0xc))(1000);
      iVar1 = (**(code **)(*param_1 + 0x44))();
    } while (iVar1 == 0);
  }
  return;
}

