
void FUN_005b8390(undefined4 param_1)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_104;
  undefined1 local_100 [256];
  
  local_104 = 0x3b2c20;
  FUN_005b8120(param_1,local_100,0x100);
  pcVar1 = (char *)FUN_0063864b(local_100,&local_104);
  do {
    if (pcVar1 == (char *)0x0) {
      return;
    }
    if ((*pcVar1 == '-') || (*pcVar1 == '!')) {
      iVar2 = FUN_005b8420(pcVar1 + 1);
      if (-1 < iVar2) {
        uVar3 = 0;
        goto LAB_005b83f8;
      }
    }
    else {
      iVar2 = FUN_005b8420(pcVar1);
      if (-1 < iVar2) {
        uVar3 = 1;
LAB_005b83f8:
        FUN_005b8300(iVar2,uVar3);
      }
    }
    pcVar1 = (char *)FUN_0063864b(0,&local_104);
  } while( true );
}

