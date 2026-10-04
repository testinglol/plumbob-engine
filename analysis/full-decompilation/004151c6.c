
void __fastcall FUN_004151c6(int *param_1)

{
  int iVar1;
  
  if ((undefined4 *)param_1[8] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[8])(1);
  }
  param_1[8] = 0;
  iVar1 = DAT_006f0bb8;
  if (DAT_006f0bb8 != 0) {
    FUN_004c7205();
    FUN_006321f0(iVar1);
  }
  DAT_006f0bb8 = 0;
  FUN_0057a5b1();
  iVar1 = param_1[4];
  if (iVar1 != 0) {
    FUN_0057a172();
    FUN_006321f0(iVar1);
  }
  iVar1 = param_1[6];
  param_1[4] = 0;
  if (iVar1 != 0) {
    FUN_004848ae();
    FUN_006321f0(iVar1);
  }
  param_1[6] = 0;
  if ((undefined4 *)*param_1 != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)*param_1)(1);
  }
  iVar1 = param_1[9];
  *param_1 = 0;
  if (iVar1 != 0) {
    FUN_00424560();
    FUN_006321f0(iVar1);
  }
  param_1[9] = 0;
  if ((undefined4 *)param_1[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[3])(1);
  }
  param_1[3] = 0;
  FUN_004c5c4a();
  iVar1 = DAT_006f0ba8;
  if (DAT_006f0ba8 != 0) {
    FUN_004c4ebf();
    FUN_006321f0(iVar1);
  }
  DAT_006f0ba8 = 0;
  FUN_004a0cb9();
  iVar1 = DAT_006efc64;
  if (DAT_006efc64 != 0) {
    FUN_004a0124();
    FUN_006321f0(iVar1);
  }
  DAT_006efc64 = 0;
  if (param_1[1] != 0) {
    (*(code *)**(undefined4 **)(param_1[1] + 8))(1);
  }
  param_1[1] = 0;
  FUN_00584787();
  if ((undefined4 *)param_1[0xc] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xc])(1);
  }
  param_1[0xc] = 0;
  if ((undefined4 *)param_1[0xb] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xb])(1);
  }
  param_1[0xb] = 0;
  if (param_1[5] != 0) {
    FUN_00415317();
    param_1[5] = 0;
  }
  if (param_1[10] != 0) {
    (*(code *)**(undefined4 **)(param_1[10] + 4))(1);
  }
  param_1[10] = 0;
  return;
}

