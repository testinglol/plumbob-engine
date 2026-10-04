
undefined2 __fastcall FUN_004b8970(int param_1)

{
  undefined2 uVar1;
  
  uVar1 = FUN_004a44f7(0xff8080);
  *(undefined2 *)(param_1 + 4) = uVar1;
  uVar1 = FUN_004a44f7(0);
  *(undefined2 *)(param_1 + 6) = uVar1;
  uVar1 = FUN_004a44f7(0xffffff);
  *(undefined2 *)(param_1 + 8) = uVar1;
  return 1;
}

