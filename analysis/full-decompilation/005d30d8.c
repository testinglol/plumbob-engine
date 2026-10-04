
void __fastcall FUN_005d30d8(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_FUN_00673590;
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}

