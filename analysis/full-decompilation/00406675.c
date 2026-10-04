
void __thiscall FUN_00406675(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  do {
    bVar1 = false;
    iVar2 = 0;
    iVar3 = param_1 + 0x10;
    do {
      if (bVar1) {
LAB_00406697:
        if (iVar2 < 7) {
          *(undefined4 *)(iVar3 + -4) = *(undefined4 *)(iVar3 + 0x10);
          FUN_0049ebb2(iVar3 + 0x14);
          *(undefined2 *)(iVar3 + 0xc) = *(undefined2 *)(iVar3 + 0x20);
        }
        else {
          *(undefined4 *)(iVar3 + -4) = 0;
        }
      }
      else if (*(int *)(iVar3 + -4) == param_2) {
        *(undefined4 *)(iVar3 + -4) = 0;
        bVar1 = true;
        goto LAB_00406697;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x14;
    } while (iVar2 < 8);
    if (!bVar1) {
      return;
    }
  } while( true );
}

