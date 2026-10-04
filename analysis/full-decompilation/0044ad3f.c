
undefined4 FUN_0044ad3f(undefined4 param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  short sVar3;
  undefined2 extraout_var;
  undefined2 uVar4;
  
  pcVar2 = param_2;
  param_2 = (char *)(CONCAT31(param_2._1_3_,param_2[4]) & 0xffffff01);
  cVar1 = *pcVar2;
  if (cVar1 == '\0') {
    sVar3 = FUN_00453181(pcVar2[1],*(undefined2 *)(pcVar2 + 2),0);
    FUN_004765df((int)sVar3,param_2);
    uVar4 = extraout_var;
  }
  else {
    uVar4 = 0;
    if (cVar1 != '\x01') {
      if (cVar1 != '\x02') {
        return 1;
      }
      sVar3 = FUN_00453181(pcVar2[1],*(undefined2 *)(pcVar2 + 2),0);
      FUN_00476afb((int)sVar3,param_2);
      return 1;
    }
  }
  sVar3 = FUN_00453181(CONCAT22(uVar4,(ushort)(byte)pcVar2[1]),
                       CONCAT22(uVar4,*(undefined2 *)(pcVar2 + 2)),0);
  FUN_00476a13((int)sVar3,param_2);
  return 1;
}

