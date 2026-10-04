
void FUN_004b1779(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_004b16b0(&local_14);
  if ((local_14 < local_c) && (local_10 < local_8)) {
    FUN_004b06db(&local_14,0xffffff,param_1,0);
    if (DAT_006e4870 == '\0') {
      cVar1 = FUN_004b466e();
      if (cVar1 != '\0') {
        piVar2 = &local_14;
        FUN_005caf36(piVar2);
        FUN_005cddcf(piVar2);
      }
    }
  }
  return;
}

