
void __fastcall FUN_005dfb96(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &PTR_FUN_00673d4c;
  if ((undefined4 *)param_1[0x13] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x13])(1);
    param_1[0x13] = 0;
  }
  FUN_005deb54();
  if ((undefined4 *)param_1[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[4])(1);
  }
  iVar1 = param_1[0xb];
  if (iVar1 != 0) {
    FUN_005b8770();
    FUN_006321f0(iVar1);
  }
  return;
}

