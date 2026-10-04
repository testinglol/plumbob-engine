
void __fastcall FUN_004370fd(int param_1)

{
  *(undefined4 *)(param_1 + 0x74) = 5;
  if ((*(int *)(param_1 + 0x70) != 0) && (*(char *)(param_1 + 0x69) == '\0')) {
    *(undefined4 *)(*(int *)(param_1 + 0x70) + 0x148) = 0;
    if ((*(int *)(DAT_006f2a08 + 0x84) != 0) &&
       ((*(int *)(*(int *)(DAT_006f2a08 + 0x84) + 0x11ac) != 0 &&
        (*(char *)(param_1 + 0x6c) != '\0')))) {
      FUN_004ff854(*(int *)(param_1 + 0x70) + 0x7c);
    }
    (**(code **)(*DAT_006fe8bc + 0x18))();
    FUN_005da4c7(*(undefined4 *)(param_1 + 0x70));
    *(undefined4 *)(param_1 + 0x70) = 0;
  }
  return;
}

