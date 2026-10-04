
char __thiscall FUN_00452129(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  
  iVar3 = param_2[1] - param_1[1];
  iVar5 = *param_2 - *param_1;
  iVar2 = iVar3;
  if (iVar3 < 0) {
    iVar2 = -iVar3;
  }
  iVar1 = iVar5;
  if (iVar5 < 0) {
    iVar1 = -iVar5;
  }
  if (iVar2 * 2 < iVar1) {
    cVar4 = '\x04';
  }
  else {
    cVar4 = (iVar2 <= iVar1 * 2) + '\x02';
  }
  if (iVar3 < 0) {
    if (cVar4 == '\x02') {
      cVar4 = '\x06';
    }
    else if (cVar4 == '\x03') {
      cVar4 = '\x05';
    }
  }
  if (iVar5 < 0) {
    if (cVar4 == '\x03') {
      cVar4 = '\x01';
    }
    else if (cVar4 == '\x04') {
      cVar4 = '\0';
    }
    else if (cVar4 == '\x05') {
      cVar4 = '\a';
    }
  }
  return cVar4;
}

