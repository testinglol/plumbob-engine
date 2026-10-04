
void FUN_0040727f(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(*DAT_006e486c + 0x14);
  iVar2 = FUN_0043ac74(s_comeandsee_006c0f14);
  do {
    iVar3 = *(int *)(iVar1 + 0x30);
    while( true ) {
      if (iVar3 == 0) {
        return;
      }
      if (*(int *)(iVar3 + 0x11c) == iVar2) break;
      iVar3 = *(int *)(iVar3 + 0xe0);
    }
    FUN_0044127f(CONCAT22((short)((uint)iVar3 >> 0x10),*(undefined2 *)(iVar3 + 0xf0)));
  } while( true );
}

