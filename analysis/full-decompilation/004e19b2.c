
void FUN_004e19b2(undefined4 param_1,char param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined **local_114 [3];
  undefined1 local_108 [260];
  
  FUN_0046f824(local_108,0,0x104);
  local_114[0] = &PTR_FUN_006664e8;
  uVar2 = FUN_0041532c(0x57,0,local_114);
  FUN_004eea6b(uVar2);
  iVar3 = FUN_00425db3(param_1);
  if (iVar3 != 0) {
    FUN_004288ff(local_114,iVar3);
    if (param_2 != '\0') {
      FUN_004e609e();
      cVar1 = FUN_004e6445();
      if (cVar1 != '\0') {
        FUN_004e2fc2(param_1);
      }
    }
  }
  return;
}

