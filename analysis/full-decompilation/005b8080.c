
void FUN_005b8080(undefined4 param_1)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 local_104;
  undefined1 local_102;
  undefined1 local_100 [256];
  
  local_104 = DAT_00672638;
  local_102 = DAT_0067263a;
  FUN_005b8120(param_1,local_100,0x100);
  pcVar1 = (char *)FUN_0063864b(local_100,&local_104);
  do {
    if (pcVar1 == (char *)0x0) {
      return;
    }
    if (*pcVar1 == '-') {
      iVar2 = FUN_005b81a0(pcVar1 + 1);
      if (-1 < iVar2) {
        uVar3 = 0;
LAB_005b80ee:
        FUN_005b8050(iVar2,uVar3);
      }
    }
    else {
      iVar2 = FUN_005b81a0(pcVar1);
      if (-1 < iVar2) {
        uVar3 = 1;
        goto LAB_005b80ee;
      }
    }
    pcVar1 = (char *)FUN_0063864b(0,&local_104);
  } while( true );
}

