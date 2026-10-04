
bool FUN_004ea0e9(int param_1,int param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint local_24 [4];
  int local_14 [4];
  
  cVar1 = FUN_004e9982(param_1);
  cVar2 = FUN_004e9982(param_2);
  if (cVar1 == '\0') {
    if (cVar2 != '\0') goto LAB_004ea115;
  }
  else {
    if (cVar2 == '\0') {
      return true;
    }
LAB_004ea115:
    if (cVar1 == '\0') {
      return false;
    }
  }
  iVar3 = FUN_004e9744(param_1);
  iVar4 = FUN_004e9744(param_2);
  if (iVar3 == 0) {
    if (iVar4 == 0) goto LAB_004ea13d;
  }
  else if (iVar4 == 0) {
    return true;
  }
  if (iVar3 == 0) {
    return false;
  }
LAB_004ea13d:
  uVar5 = FUN_004e99a9();
  FUN_004ea17e(uVar5,param_1,local_24);
  FUN_004ea17e(uVar5,param_2,local_14);
  if (local_14[0] < (int)local_24[0]) {
    return true;
  }
  if ((int)local_24[0] < local_14[0]) {
    return false;
  }
  return param_1 < param_2;
}

