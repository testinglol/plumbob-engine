
void __thiscall FUN_00585a70(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  
  (**(code **)(*param_1 + 0xac))();
  piVar5 = param_1 + 0x33;
  do {
    iVar1 = param_1[0x34];
    iVar2 = *piVar5;
    iVar4 = 0;
    while( true ) {
      if (iVar1 - iVar2 >> 2 <= iVar4) {
        return;
      }
      cVar3 = FUN_004317d5(*(int *)(*piVar5 + iVar4 * 4) + 4,param_2);
      if (cVar3 != '\0') break;
      iVar4 = iVar4 + 1;
    }
    iVar4 = iVar4 * 4;
    FUN_0058379c();
    iVar1 = *(int *)(*piVar5 + iVar4);
    if (iVar1 != 0) {
      FUN_005836d2();
      FUN_006321f0(iVar1);
    }
    *(undefined4 *)(*piVar5 + iVar4) = 0;
    FUN_005db2f2(*piVar5 + iVar4);
  } while( true );
}

