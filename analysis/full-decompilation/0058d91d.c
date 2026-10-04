
void __thiscall FUN_0058d91d(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  
  piVar1 = (int *)(param_1 + 0x274);
  do {
    iVar2 = *(int *)(param_1 + 0x278);
    iVar3 = *piVar1;
    iVar5 = 0;
    while( true ) {
      if (iVar2 - iVar3 >> 2 <= iVar5) {
        return;
      }
      cVar4 = FUN_004317d5(*(int *)(*piVar1 + iVar5 * 4) + 4,param_2);
      if (cVar4 != '\0') break;
      iVar5 = iVar5 + 1;
    }
    iVar5 = iVar5 * 4;
    FUN_0058379c();
    iVar2 = *(int *)(iVar5 + *piVar1);
    if (iVar2 != 0) {
      FUN_005836d2();
      FUN_006321f0(iVar2);
    }
    *(undefined4 *)(iVar5 + *piVar1) = 0;
    FUN_005db2f2(iVar5 + *piVar1);
  } while( true );
}

