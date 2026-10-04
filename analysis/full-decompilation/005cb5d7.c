
void __fastcall FUN_005cb5d7(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_FUN_0067347c;
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}

