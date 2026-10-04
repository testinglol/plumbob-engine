
void __fastcall FUN_0044651b(int param_1)

{
  undefined4 *puVar1;
  undefined4 *local_14;
  undefined4 *local_c;
  
  if (*(char *)(param_1 + 0xac) != '\0') {
    if (*(int *)(param_1 + 0xb0) != *(int *)(param_1 + 0xb4)) {
      puVar1 = *(undefined4 **)(param_1 + 0xb4);
      for (local_c = *(undefined4 **)(param_1 + 0xb0); local_c != puVar1; local_c = local_c + 1) {
        FUN_004472e2(*local_c);
      }
      FUN_00448aa5(*(undefined4 *)(param_1 + 0xb0),*(undefined4 *)(param_1 + 0xb4));
    }
    if (*(int *)(param_1 + 0xbc) != *(int *)(param_1 + 0xc0)) {
      puVar1 = *(undefined4 **)(param_1 + 0xc0);
      for (local_14 = *(undefined4 **)(param_1 + 0xbc); local_14 != puVar1; local_14 = local_14 + 1)
      {
        FUN_00446f29(*local_14);
      }
      FUN_00448aa5(*(undefined4 *)(param_1 + 0xbc),*(undefined4 *)(param_1 + 0xc0));
    }
    *(undefined1 *)(param_1 + 0xac) = 0;
  }
  return;
}

