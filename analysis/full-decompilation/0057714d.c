
void __fastcall FUN_0057714d(int param_1)

{
  undefined4 uStack_14;
  int local_10;
  int iStack_4;
  
  *(undefined4 *)(param_1 + 4) = 0;
  iStack_4 = param_1;
  if (*(int **)(param_1 + 0xc) != (int *)0x0) {
    local_10 = 0x577162;
    (**(code **)(**(int **)(param_1 + 0xc) + 0x18))();
    local_10 = 0x57716a;
    FUN_005ed911();
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  uStack_14 = *(undefined4 *)(param_1 + 0x24);
  local_10 = uStack_14;
  FUN_00602902(&uStack_14);
  FUN_00578f92(&iStack_4);
  if (*(int *)(param_1 + 0x10) != 0) {
    local_10 = 0x57719a;
    FUN_005771b0();
    local_10 = *(int *)(param_1 + 0x10);
    if (local_10 != 0) {
      uStack_14 = 0x5771a7;
      FUN_006321f0();
    }
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return;
}

