
void __fastcall FUN_0048bab7(int param_1)

{
  undefined4 uVar1;
  
  if (*(int **)(param_1 + 0x2c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x2c) + 0x50))(1);
  }
  if (*(int *)(param_1 + 0x5c) != 0) {
    FUN_00495076();
  }
  *(undefined1 *)(param_1 + 0x70) = 1;
  uVar1 = FUN_00492b26();
  FUN_00540a5b(uVar1);
  FUN_00540eb1(uVar1);
  FUN_00492bc4();
  FUN_0040766a(0x101,0);
  FUN_0040766a(0x91,0);
  FUN_004864ed(0,0xffffffff);
  *(undefined4 *)(*(int *)(param_1 + 0x5c) + 0xe064) = 0;
  return;
}

