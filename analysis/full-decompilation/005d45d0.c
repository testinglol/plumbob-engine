
void __fastcall FUN_005d45d0(undefined4 *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)param_1[0x15];
  *param_1 = &PTR_FUN_00673644;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    param_1[0x15] = 0;
  }
  piVar1 = (int *)param_1[0x16];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    param_1[0x16] = 0;
  }
  if ((int *)param_1[0x23] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x23] + 8))();
    param_1[0x23] = 0;
  }
  return;
}

