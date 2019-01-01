class Solution(object):
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        real_emails = set()
        for e in emails:
            local_name, domain_name = e.split('@')
            local_name = local_name.split('+')[0].replace('.', '')
            real_emails.add(local_name + '@' + domain_name)
        return len(real_emails)
