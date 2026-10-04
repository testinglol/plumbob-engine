
void __fastcall FUN_004403d7(int param_1)

{
  char cVar1;
  int local_c;
  int *local_8;
  
  *(undefined1 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(DAT_006e54d8 + 0x84);
  local_8 = (int *)(param_1 + 0x4c);
  FUN_00448aa5(*local_8,*(undefined4 *)(param_1 + 0x50));
  for (local_c = *(int *)(param_1 + 0x30); local_c != 0; local_c = *(int *)(local_c + 0xe0)) {
    cVar1 = FUN_00433136(local_c + 0xfc);
    if (cVar1 == '\0') {
      FUN_0044845a(&local_c);
    }
  }
  if (1 < (uint)(local_8[1] - *local_8 >> 2)) {
    FUN_00449cfc(*local_8,local_8[1],FUN_004404c9);
  }
  return;
}

