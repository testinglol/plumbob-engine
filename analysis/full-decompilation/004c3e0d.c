
byte FUN_004c3e0d(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  byte bVar3;
  undefined1 extraout_var;
  int unaff_EBP;
  undefined4 local_4;
  
  local_4 = 0x4c3e17;
  FUN_00634c24();
  uVar1 = *(undefined1 *)(unaff_EBP + 8);
  uVar2 = *(undefined1 *)(unaff_EBP + 0xc);
  *(undefined1 *)(unaff_EBP + 8) = uVar1;
  *(undefined1 *)(unaff_EBP + 9) = uVar2;
  *(undefined1 *)(unaff_EBP + 10) = 1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 **)(unaff_EBP + 0xc) = &local_4;
  local_4 = CONCAT13(extraout_var,CONCAT12(1,CONCAT11(uVar2,uVar1)));
  bVar3 = FUN_004893e4();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return (byte)~bVar3 >> 5 & 1;
}

