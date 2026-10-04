
char * __thiscall FUN_004aefd1(char *param_1,int param_2)

{
  char cVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  char cVar5;
  
  iVar4 = FUN_004aeea6();
  if (param_2 == 0) {
    return param_1;
  }
  if (iVar4 == 0) {
    return param_1;
  }
  cVar1 = *param_1;
  cVar2 = param_1[1];
  if (iVar4 < 2) {
    cVar5 = param_2._3_1_;
    cVar3 = param_2._2_1_;
  }
  else {
    cVar5 = param_1[3];
    cVar3 = param_1[2];
  }
  if (param_2 == 1) {
    *param_1 = -cVar2;
    param_1[1] = cVar1;
    if (iVar4 < 2) {
      return param_1;
    }
    param_1[2] = -cVar5;
  }
  else {
    if (param_2 == 2) {
      *param_1 = -cVar1;
      param_1[1] = -cVar2;
      if (iVar4 < 2) {
        return param_1;
      }
      param_1[2] = -cVar3;
      param_1[3] = -cVar5;
      return param_1;
    }
    if (param_2 != 3) {
      return param_1;
    }
    *param_1 = cVar2;
    param_1[1] = -cVar1;
    if (iVar4 < 2) {
      return param_1;
    }
    param_1[2] = cVar5;
    cVar3 = -cVar3;
  }
  param_1[3] = cVar3;
  return param_1;
}

