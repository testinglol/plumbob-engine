
void FUN_0051d7af(int *param_1,char param_2)

{
  if (param_2 != '\0') {
                    /* WARNING: Could not recover jumptable at 0x0051d7bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x94))();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0051d7c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x98))();
  return;
}

