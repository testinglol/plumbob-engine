
void FUN_00480164(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  undefined1 uVar2;
  byte bVar3;
  char cVar4;
  undefined1 uVar5;
  
  FUN_0046fa24(0x28);
  bVar3 = *(byte *)(param_1 + 1) & 0x7f;
  bVar1 = *(byte *)(param_1 + 1) & 0x80;
  if (bVar1 == 0) {
    cVar4 = '\n';
  }
  else {
    cVar4 = *(char *)((int)param_1 + 5);
  }
  if (cVar4 == '\n') {
    if (bVar1 == 0) {
      cVar4 = '\0';
    }
    else {
      cVar4 = *(char *)((int)param_1 + 7);
    }
    if (cVar4 == '\0') goto LAB_004801e4;
  }
  if (bVar1 == 0) {
    uVar5 = 0;
    uVar2 = 10;
  }
  else {
    uVar5 = *(undefined1 *)((int)param_1 + 7);
    uVar2 = *(undefined1 *)((int)param_1 + 5);
  }
  FUN_0047e457(*(undefined4 *)(param_2 + 0xc),uVar2,uVar5,param_3,param_4);
  FUN_0046f847(s____next_006c5734,0xffffffff);
LAB_004801e4:
  FUN_00465b21(&DAT_006e54e8,*(undefined4 *)(DAT_006e486c + 0xc),0xa4,bVar3 + 1);
  FUN_0046f917(&DAT_006e54e8,0xffffffff);
  if ((bVar3 == 4) || (bVar3 == 7)) {
    FUN_0046f847(&DAT_006c3d7c,0xffffffff);
    FUN_0048026d(*param_1,param_3);
  }
  else if (bVar3 == 9) {
    FUN_0046f847(&DAT_006c3d7c,0xffffffff);
    FUN_0047e457(*(undefined4 *)(param_2 + 0xc),0x19,*(undefined1 *)((int)param_1 + 6),param_3,
                 param_4);
  }
  FUN_0046fa24(0x29);
  return;
}

