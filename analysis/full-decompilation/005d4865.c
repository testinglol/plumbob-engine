
void __fastcall FUN_005d4865(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_FUN_00673680;
  FUN_005d2835(param_1);
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    param_1[1] = 0;
  }
  piVar1 = (int *)param_1[2];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    param_1[2] = 0;
  }
  return;
}

