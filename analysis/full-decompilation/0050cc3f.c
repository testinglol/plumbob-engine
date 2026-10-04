
void __thiscall
FUN_0050cc3f(int param_1,undefined4 param_2,undefined1 param_3,undefined1 param_4,undefined4 param_5
            )

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 0xe0) == '\0') {
    *(undefined1 *)(param_1 + 0xe0) = 1;
  }
  *(undefined1 *)(param_1 + 0x110) = param_3;
  *(undefined1 *)(param_1 + 0x111) = param_4;
  *(undefined4 *)(param_1 + 0x10c) = param_2;
  *(undefined4 *)(param_1 + 0x114) = param_5;
  uVar1 = FUN_004573f9();
  FUN_004ce4a9(uVar1);
  FUN_004cdca5(uVar1);
  FUN_0050cca5();
  return;
}

