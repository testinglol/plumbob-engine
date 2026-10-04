
void FUN_005160e4(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  FUN_004e609e();
  cVar1 = FUN_004e60c2();
  if (cVar1 == '\0') {
    cVar1 = FUN_005e4f8d();
    if (cVar1 != '\0') {
      uVar2 = 0;
      goto LAB_0051611b;
    }
  }
  else {
    cVar1 = FUN_005e4f8d();
    if (cVar1 == '\0') {
      uVar2 = 1;
LAB_0051611b:
      FUN_005e4f65(uVar2);
    }
  }
  cVar1 = FUN_004e60ed();
  if (cVar1 == '\0') {
    cVar1 = FUN_005e4f8d();
    if (cVar1 == '\0') goto LAB_00516154;
    uVar2 = 0;
  }
  else {
    cVar1 = FUN_005e4f8d();
    if (cVar1 != '\0') goto LAB_00516154;
    uVar2 = 1;
  }
  FUN_005e4f65(uVar2);
LAB_00516154:
  FUN_005dcd25(param_1);
  return;
}

