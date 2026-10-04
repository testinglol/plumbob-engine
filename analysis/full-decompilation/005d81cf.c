
void FUN_005d81cf(char *param_1)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  cVar1 = *param_1;
  if ((((cVar1 != '\0') && (cVar1 == '0')) && (cVar2 = param_1[1], cVar2 != '\0')) &&
     ((cVar2 == 'x' || (cVar2 == 'X')))) {
    (*(code *)PTR_FUN_006d7004)(param_1,0,0x10);
    return;
  }
  uVar4 = 10;
  pcVar3 = param_1;
  do {
    if (cVar1 == '\0') {
LAB_005d822c:
      (*(code *)PTR_FUN_006d7004)(param_1,0,uVar4);
      return;
    }
    if ((('`' < cVar1) && (*pcVar3 < 'g')) || (('@' < *pcVar3 && (*pcVar3 < 'G')))) {
      uVar4 = 0x10;
      goto LAB_005d822c;
    }
    cVar1 = pcVar3[1];
    pcVar3 = pcVar3 + 1;
  } while( true );
}

