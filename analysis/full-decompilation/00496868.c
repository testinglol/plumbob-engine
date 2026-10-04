
void __thiscall FUN_00496868(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 local_c;
  
  *(undefined1 *)(param_1 + 0xe02c) = *(undefined1 *)param_2;
  *(undefined1 *)(param_1 + 0xe02d) = *(undefined1 *)((int)param_2 + 1);
  *(undefined1 *)(param_1 + 0xe02e) = *(undefined1 *)((int)param_2 + 2);
  *(undefined1 *)(param_1 + 0xe048) = *(undefined1 *)param_2;
  *(undefined1 *)(param_1 + 0xe049) = *(undefined1 *)((int)param_2 + 1);
  *(undefined1 *)(param_1 + 0xe04a) = *(undefined1 *)((int)param_2 + 2);
  *(undefined1 *)(param_1 + 0xe04b) = *(undefined1 *)param_2;
  *(undefined1 *)(param_1 + 0xe04c) = *(undefined1 *)((int)param_2 + 1);
  *(undefined1 *)(param_1 + 0xe04d) = *(undefined1 *)((int)param_2 + 2);
  local_c = CONCAT13((char)((uint)(param_1 + 0xe04b) >> 0x18),*(undefined3 *)param_2);
  param_2 = &local_c;
  iVar1 = FUN_004796d9(&param_2);
  *(undefined1 *)(param_1 + 0xe02f) = *(undefined1 *)(iVar1 + 1);
  local_c = 0x4968e8;
  FUN_00495076();
  *(undefined4 *)(param_1 + 0xe054) = 0;
  *(undefined4 *)(param_1 + 0xe064) = 0;
  return;
}

