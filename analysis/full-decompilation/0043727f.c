
void FUN_0043727f(void)

{
  short sVar1;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  int unaff_EBP;
  
  FUN_00634c24();
  if (DAT_006e4b3c == 0) {
    FUN_00464479(unaff_EBP + -0x1c,0,0,CONCAT22(extraout_var,DAT_006c2aa2 << 8),
                 CONCAT22(extraout_var,DAT_006c2aa0));
    FUN_00464479(unaff_EBP + -0x24,0,0,CONCAT22(extraout_var_00,DAT_006c2aa2),
                 CONCAT22(extraout_var_00,DAT_006c2aa0));
    sVar1 = FUN_00458fae(unaff_EBP + -0x1c);
    if (sVar1 != 0) {
      *(undefined1 *)(unaff_EBP + -0xd) = 0;
      FUN_004591d4(0);
      FUN_0046cd8b(s_Arial_006c2aa4,7,0);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_0046ce51();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0046ceb8(unaff_EBP + -0x30);
      FUN_0041fea4(unaff_EBP + -0x1c);
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      do {
        *(undefined1 *)(unaff_EBP + -0xe) = *(undefined1 *)(unaff_EBP + -0x14);
        FUN_0041fec4(unaff_EBP + -0xe,1,unaff_EBP + -0x24,0xfffffffe);
        FUN_004643bc(unaff_EBP + -0x24,CONCAT22(extraout_var_01,DAT_006c2aa2),0);
        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
      } while (*(int *)(unaff_EBP + -0x14) < 0x100);
      FUN_0046ceb8(0);
      FUN_00459112();
      FUN_0042004f();
      DAT_006e4b3c = 1;
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_0046ce6a();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0046ce6a();
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

