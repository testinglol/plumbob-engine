
void FUN_0047efb2(void)

{
  undefined4 uVar1;
  short *psVar2;
  int unaff_EBP;
  char *pcVar3;
  
  FUN_00634c24();
  FUN_0046f824(unaff_EBP + -0x330,0,0x100);
  uVar1 = *(undefined4 *)(unaff_EBP + 0x10);
  *(undefined ***)(unaff_EBP + -0x33c) = &PTR_FUN_00666524;
  FUN_0046fa24(0x28);
  psVar2 = *(short **)(unaff_EBP + 8);
  if (psVar2[2] == 0) {
    FUN_0046f847(s_clear_006c53ac,0xffffffff);
  }
  else {
    FUN_004169e6(*(undefined1 *)((int)psVar2 + 3));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_0046f824(unaff_EBP + -0x10c,0,0x100);
    *(undefined ***)(unaff_EBP + -0x118) = &PTR_FUN_00666524;
    FUN_00416a87(unaff_EBP + -0x118);
    FUN_0046f917(unaff_EBP + -0x118,0xffffffff);
    FUN_0046f847(&DAT_006c53a8,0xffffffff);
    FUN_00416b4c((char)psVar2[1],unaff_EBP + -0x118);
    FUN_0046f917(unaff_EBP + -0x118,0xffffffff);
    if (((psVar2[1] & 0xff00U) == 0x700) && ((char)psVar2[1] == '\x02')) {
      FUN_0046f847(&DAT_006c3d7c,0xffffffff);
      FUN_0047e457(*(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 0xc),0x19,*psVar2 >> 1,uVar1,
                   *(undefined4 *)(unaff_EBP + 0x14));
    }
    if ((psVar2[3] & 0x1000U) != 0) {
      FUN_0046f847(&DAT_006c53a4,0xffffffff);
      FUN_0047e457(*(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 0xc),8,0,uVar1,
                   *(undefined4 *)(unaff_EBP + 0x14));
    }
    FUN_0046f847(&DAT_006c539c,0xffffffff);
    FUN_00465b21(&DAT_006e54e8,*(undefined4 *)(DAT_006e486c + 0xc),0xa2,*(byte *)(psVar2 + 3) + 1);
    FUN_0046f917(&DAT_006e54e8,0xffffffff);
    FUN_0046f847(s_balloon_006c5390,0xffffffff);
    if (psVar2[2] == -1) {
      pcVar3 = s_forever_006c5388;
    }
    else {
      FUN_0046f847(&DAT_006c5380,0xffffffff);
      FUN_0046fa40((int)psVar2[2]);
      if ((psVar2[3] & 0x800U) == 0) {
        pcVar3 = s_ticks_006c5370;
      }
      else {
        pcVar3 = s_loops_006c5378;
      }
    }
    FUN_0046f847(pcVar3,0xffffffff);
    if ((psVar2[3] & 0x100U) != 0) {
      FUN_0046f847(s___show_when_inactive_006c5358,0xffffffff);
    }
    if ((psVar2[3] & 0x200U) != 0) {
      FUN_0046f847(s___crossed_out_006c5348,0xffffffff);
    }
    if ((psVar2[3] & 0x400U) != 0) {
      FUN_0046f847(s___anim_reversed_006c5338,0xffffffff);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00416a38();
  }
  FUN_0046fa24(0x29);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

